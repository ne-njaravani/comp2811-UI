
# Water Quality Monitoring Application

This project is a Water Quality Monitoring application made for Qt6 (built with Qt6.7.3), C++, and CMake. It allows users to interact with water quality data, load CSV files, and visualize pollutant compliance trends through various dashboards.

## Requirements

- Qt6 (make sure to install it and provide the correct path to CMake)
- CMake 3.10+ 
- A C++ compiler (e.g., GCC or Clang)

## Setup Instructions

1. **Clone the repository**:

   git clone <repository-url>
   cd comp2811-UI

2. **Install Qt6**:
   Ensure that Qt6 is installed on your system. You can download it from [Qt's official website](https://www.qt.io/download) or use a package manager (or use the Qt Extension of VSCode).

3. **Configure the build environment**:
   Navigate to the root folder of the project and run the following command to configure the project using CMake:

   cmake -DCMAKE_PREFIX_PATH=<path-to-qt6> -S . -B build

   Replace `<path-to-qt6>` with the path where Qt6 is installed.

4. **Build the project**:
   After configuration, you can build the project by running:

   cmake --build build

5. **Run the application**:
   After building the project, you can run the application using:

   ./build/watertool

Note: If using VSCode, edit the settings.json file in the .vscode folder and run using the extension.

## Features

- **CSV File Upload**: Allows users to upload a custom CSV file containing water quality data.
- **Dashboard**: Displays various pollutants and their compliance status.
- **Dynamic Search**: Filters cards based on text input.
- **Navigation**: Navigate to different data views like Pollutant Overview, Compliance Dashboard, and more.
- **Responsive Design**: The application layout adjusts to the screen size, ensuring all data fits.

## License

This project is a coursework for a university module, therefore, it is not made with the intention of making a profit.
