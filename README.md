
 # students-mechazilla
This is our first game in C++ with SFML. We are still learning!


# MechazillaGame

MechazillaGame is a game developed in C++ using the [SFML](https://www.sfml-dev.org/) library. This project is designed to be easy to set up and run on any computer with the proper configuration.

---

## 🚀 Prerequisites

Before you can run the project, ensure your system meets the following requirements:

1. **Operating System**: Windows, macOS, or Linux.
2. **Compatible IDE**: Visual Studio 2022 (or newer) with C++ development tools installed.
3. **SFML Library**: Download [SFML 2.5.1](https://www.sfml-dev.org/download.php) (version for Visual Studio).

---

## 🛠️ Setting Up the Project in Visual Studio

1. **Clone the repository**:
   Open your terminal and run:
   ~~~bash  
   git clone https://github.com/knocek/students-mechazilla.git
   ~~~

2. **Open the Project in Visual Studio**
   Open the MechazillaGame.sln file in Visual Studio.
   Select the correct build configuration:
   Configuration: Debug or Release.
   Platform: x64.

3. **Set Up SFML**
   1. Navigate to the folder where you installed SFML.
   2. Copy the required .dll files from SFML/bin to the x64/Debug (or x64/Release) folder in your project directory:

  Debug:
  ~~~bash  
  sfml-graphics-d.dll
  sfml-window-d.dll
  sfml-system-d.dll
  sfml-audio-d.dll
  sfml-network-d.dll 
  ~~~~

  Release (no -d suffix):
  ~~~bash
  sfml-graphics.dll
  sfml-window.dll
  sfml-system.dll
  sfml-audio.dll
  sfml-network.dll
  ~~~

   3. Ensure the following SFML folders are properly configured in Visual Studio:

   Include Path: Add SFML/include to the project's include directories.
   Library Path: Add SFML/lib to the project's library directories.
   Dependencies: Link the following libraries in Visual Studio:
   ~~~bash
   sfml-graphics-d.lib
   sfml-window-d.lib
   sfml-system-d.lib
   sfml-audio-d.lib
   sfml-network-d.lib
   ~~~

## 🔧 Building and Running the Game
In Visual Studio, click Build → Build Solution or press Ctrl+Shift+B.
After the build completes, find the executable file in:

- x64/Debug/MechazillaGame.exe
- x64/Release/MechazillaGame.exe

Run the .exe file to start the game!


## 🔧 Troubleshooting
Problem: Missing .dll files
Ensure you copied the .dll files from SFML/bin to the appropriate output folder (x64/Debug or x64/Release).

Problem: Executable file not generated
Verify that the correct configuration (x64/Debug or x64/Release) is selected.
Ensure all SFML paths (include and lib) are properly set up in the project settings.


## 💡 Useful Links
- [SFML Official Documentation](https://www.sfml-dev.org/documentation/2.6.2/)
- [Download SFML](https://www.sfml-dev.org/download.php)
- [Visual Studio 2022](https://visualstudio.microsoft.com/pl/downloads/)