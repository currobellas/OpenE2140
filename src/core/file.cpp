//
// Created by Ion Agorria on 12/04/18
//
#include <SDL_rwops.h>
#include "file.h"
#include "utils.h"

File::~File() {
    //Close open file if any
    if (file) {
        SDL_RWclose(file);
        file = nullptr;
    }
}

bool File::open(const std::string& path, const File::FileMode& mode, std::string& error) {
    //Check if this file is open
    if (file) {
        if (error != nullptr) {
            error = "File is already open!";
        }
        return false;
    }

    //Convert mode enum to SDL mode string
    const char* modeChars;
    switch (mode) {
        case FileMode::Read:
            modeChars = "rb";
            break;
        case FileMode::Write:
            modeChars = "wb";
            break;
    }

    //Open file path with mode
    file = SDL_RWFromFile(path.c_str(), modeChars);

    //Get and check any errors
    std::string sdlError = Utils::checkSDLError();
    if (sdlError.empty()) {
        return true;
    } else {
        file = nullptr;
        if (error != nullptr) {
            error = sdlError;
        }
        return false;
    }
}