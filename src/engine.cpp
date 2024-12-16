#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

std::vector<std::string> splitString(std::string str, char del)
{
    std::stringstream ss(str);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(ss, token, del))
    {
        tokens.push_back(token);
    }

    return tokens;
}

void writeToFile(std::string path, std::string text)
{
  if (!fs::exists(path)){
    std::ofstream file(path);
    file << text;
    file.close();
    return;
  }

  fs::remove(path); // To Override
  std::ofstream file(path);
  file << text;
  file.close();
}

std::string readFromFile(const std::string& path) {
    if (!fs::exists(path)) {
        std::cerr << "File not found: " << path << "\n";
        return "";  // Return an empty string if the file doesn't exist
    }

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << path << "\n";
        return "";  // Return an empty string if the file can't be opened
    }

    std::string line;
    std::string text;

    while (std::getline(file, line)) {
        text += line + "\n";
    }

    file.close();
    return text;
}

void createNewProject(int argc, char const *argv[]);
void openProjectShell(std::string dir);

int main(int argc, char const *argv[])
{
    if (argc == 1)
        return 0;

    std::string action = argv[1];

    if (action == "--new")
    {
        createNewProject(argc, argv);
    }
    else if (action == "--open")
    {
        if (argc == 2)
        {
            std::cerr << "No project directory specified.\n";
            return -1;
        }

        std::string project = argv[2];
        openProjectShell(project);
    }
    else if (action == "--version")
    {
        std::cout << "CmdEngine v1.0.0-alpha.1.0";
    }

    else if (action == "--clean"){
        fs::remove_all("./Build");
        fs::remove_all("./Src");
        
    }

    return 0;
}

void createNewProject(int argc, char const *argv[])
{
    std::string width = "800";
    std::string height = "600";
    std::string fps = "60";
    std::string title = "Untitled Project";

    std::string params;
    std::cout << "Enter Parameters TITLE:WIDTH:HEIGHT:FPS (D = default) >> ";
    std::getline(std::cin, params);

    if (params != "d")
    {
        std::vector<std::string> paramTokens = splitString(params, ':');
        title = paramTokens.at(0);
        width = paramTokens.at(1).c_str();
        height = paramTokens.at(2).c_str();
        fps = paramTokens.at(3).c_str();
    }

    std::string currentFolder = fs::read_symlink("/proc/self/exe").remove_filename().generic_string();

    // Create game.cpp content
    
    std::string game_cpp = readFromFile(currentFolder + "BaseFiles/base_game.cpp");
    game_cpp = std::regex_replace(game_cpp, std::regex("WIDTH"), width);
    game_cpp = std::regex_replace(game_cpp, std::regex("HEIGHT"), height);
    game_cpp = std::regex_replace(game_cpp, std::regex("FRAMERATE"), fps);
    game_cpp = std::regex_replace(game_cpp, std::regex("TITLE"), ("\"" + title + "\""));

    // Create userlogic.h content
    std::string userlogic_h = readFromFile(currentFolder + "BaseFiles/base_userlogic.h");

    // Create userlogic.cpp content
    std::string userlogic_cpp = readFromFile(currentFolder + "BaseFiles/base_userlogic.cpp");

    // Create Makefile content
    std::string makefile = readFromFile(currentFolder + "BaseFiles/base_makefile");

    // Create folders
    if (!fs::exists("./Build"))
        fs::create_directory("Build");
    if (!fs::exists("./Build/Assets"))
        fs::create_directory("Build/Assets");
    if (!fs::exists("./Src"))
        fs::create_directory("Src");

    // Write files
    writeToFile("./Src/game.cpp", game_cpp);
    writeToFile("./Src/userlogic.h", userlogic_h);
    writeToFile("./Src/userlogic.cpp", userlogic_cpp);
    writeToFile("./Build/Makefile", makefile);
    system(("cp -r " + currentFolder + "CmdEngine" + " " + "./Src/").c_str());

    std::cout << "Created new project in the current directory.\n";
    std::cout << "Execute `Cmd_Engine --open .` to open the project shell.\n";
}

void openProjectShell(std::string dir)
{
    std::cout << "┌───────── PROJECT SHELL ─────────\n";

    while (true)
    {
        std::cout << "└ PROJECT ─ ";

        std::string command;
        std::getline(std::cin, command);

        if (command.empty()) continue;

        std::vector<std::string> args = splitString(command, ' ');

        std::string action = args[0];

        if (action == "clear")
        {
            system(action.c_str());
            std::cout << "┌───────── PROJECT SHELL ─────────\n";
        }
        else if (action  == "build")
        {
            fs::current_path("./Build");
            system("make");
            fs::current_path("..");
        }

        else if (action == "run")
        {
            if (!fs::exists("./Build/GAME"))
                std::cout << "└ No GAME binary found, Please build the game using `build`.\n";
            else
                system("./Build/GAME");
        }
        
        else if (action == "exit") return;
    }
}
