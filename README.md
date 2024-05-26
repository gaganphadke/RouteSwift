# RouteSwift - Bengaluru Metro Journey Planner

Welcome to the Bengaluru Metro Journey Planner!

## Introduction
This project aims to provide a convenient tool for planning journeys on the Bangalore Metro network. It utilizes a Flask web application for user interaction and a C++ backend 
for calculating optimal routes using Djikstra's algorithm.
It includes the Green line,Purple line and the Yellow line of Bengaluru Metro

## Features
- User-friendly web interface for entering start and end stations.
- Real-time pathfinding using Djikstra's algorithm.
- Clear visualization of the shortest path and distance between stations.

## Requirements
To run the application locally, you need:
- Python
- Flask
- C++ compiler (for compiling the backend)
- Compatible web browser

## Usage
1. Clone the repository to your local machine.
2. Install the required Python packages.
3. Compile the C++ backend using the provided instructions.
4. g++ -std=c++17 frontend.cpp -o metro_journey
5. Run the Flask application using `python app.py`.
6. Access the application in your web browser at `http://localhost:5000`.
7. Enter the start and end station IDs and click on "Find Path".
8. View the calculated path and distance on the result page.

