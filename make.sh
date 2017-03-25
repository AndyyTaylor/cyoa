cd ~/google\ drive/c++/cyoa/
clang++ main.cpp Source/Temp/MainScreen.cpp Source/Temp/Quad.cpp Source/Texture/Texture_Atlas.cpp Source/Camera.cpp Source/Maths/Matrix.cpp Source/Renderer/Master.cpp Source/Renderer/Simple.cpp Source/Texture/Texture.cpp Source/Shaders/Simple_Shader.cpp Source/Shaders/Shader_Loader.cpp Source/Shaders/Shader_Program.cpp Source/Model.cpp Source/Display.cpp Source/Application.cpp Source/States/Playing.cpp Source/States/Game_State.cpp -framework OpenGL -framework sfml-graphics -framework sfml-window -framework sfml-system -lGLEW -std=c++14 -o out 
echo "Script updated at $(date)" 