from flask import Flask, request, jsonify, render_template
import subprocess
import logging

app = Flask(__name__)

# Configure logging
logging.basicConfig(level=logging.DEBUG)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/dijkstra', methods=['POST'])
def dijkstra():
    try:
        data = request.get_json()
        start = data['start']
        end = data['end']
        
        logging.debug(f"Received request to find path from {start} to {end}")

        # Call the C++ executable with start and end nodes as arguments
        result = subprocess.check_output(['./metro_journey', str(start), str(end)])
        result = result.decode('utf-8')

        logging.debug(f"Result from subprocess: {result}")

        # Parse the output
        lines = result.split('\n')
        distance = lines[0].split(": ")[1]
        path = lines[1].split(": ")[1]

        response = {
            'start': start,
            'end': end,
            'path': path,
            'distance': distance
        }

        return jsonify(response)
    except subprocess.CalledProcessError as e:
        logging.error(f"Subprocess error: {str(e)}")
        return jsonify({'error': 'Error occurred'}), 500
    except Exception as e:
        logging.error(f"Unexpected error: {str(e)}")
        return jsonify({'error': 'Unexpected server error'}), 500

if __name__ == '__main__':
    app.run(debug=True)



#step1:
#g++ -std=c++17 frontend.cpp -o metro_journey

#step2:
#python app.py