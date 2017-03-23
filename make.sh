cd ~/google\ drive/c++/cyoa
clang++ main.cpp Source/Display.cpp Source/Application.cpp Source/Renderer/Master.cpp Source/Renderer/Simple.cpp -framework OpenGL -framework sfml-graphics -framework sfml-window -framework sfml-system -lGLEW -std=c++14 -o out 

echo "Script updated at $(date)"