
# Water Quality Monitoring Application

This project is a Water Quality Monitoring application made for Qt6 (built with Qt6.7.3), C++, and CMake. It allows users to interact with water quality data, load CSV files, and visualize pollutant compliance trends through various dashboards.

## Team Members (Group 18)

- **Sultan AlShaikh** - 201763715
- **Katherina Warren** - 201701314
- **Ngakudzweishe E. Njaravani** - 201694100
- **Chenyu Wang** - 201635488
- **Aman Rasheed** - 201717905

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

## Dependencies

- If using VSCode, make sure you edit the .vscode/settings.json file to redirect the CMake to your path location.
- If using Linux, all the CMake settings should be fine with the CMakeLists.txt in the root folder.

## File Structure

- .vscode
- build
- data
    - Y-2024.csv
- Ethics Documentation
- translations
- Videos
- CMakeLists.txt
- README.md
- report.pdf
- COMP2811 Feedback Fruits Tasks Overview .md
- COMP2811_CW3_Requirements.md
- (All .cpp files)
- (All .hpp files)

## License

This project is a coursework for a university module, therefore, it is not made with the intention of making a profit.
