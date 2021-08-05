#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include "CipherMode.hpp"
#include "CipherType.hpp"

#include <stdexcept>
#include <string>
#include <vector>

/**
 * \file ProcessCommandLine.hpp
 * \brief Contains the declarations of the data structures and functions associated with the processing of command-line arguments
 */

/**
 * \struct ProgramSettings
 * \brief Holds the settings of the program that can be modified by command-line arguments
 */
struct ProgramSettings {
    /// Indicates the presence of the help flag in the arguments
    bool helpRequested;
    /// Indicates the presence of the version flag in the arguments
    bool versionRequested;
    /// Name of the input file
    std::string inputFile;
    /// Name of the output file
    std::string outputFile;
    /// Key to be used in encrypting/decrypting routine
    std::string cipherKey;
    /// Flag indicating the mode in which the cipher should run (i.e. encrypt or decrypt)
    CipherMode cipherMode;
    /// Flag indicating which cipher to use (e.g. Caesar, Playfair, etc.)
    CipherType cipherType;
};

/**
 * \class MissingArgument
 * \brief Exception object indicating a missing command-line argument
 *
 * Exception object to indicate that a command-line option flag is not followed by the expected argument
 */
class MissingArgument : public std::invalid_argument {
  public:
    /** 
     * \brief Construct a MissingArgument exception
     * \param what the diagnostic message
     */
    MissingArgument(const std::string& what) : std::invalid_argument(what) {}
};

/**
 * \class UnknownArgument
 * \brief Exception object indicating an unknown command-line argument
 *
 * Exception object to indicate that an unexpected command-line argument has been encountered
 */
class UnknownArgument : public std::invalid_argument {
  public:
    /** 
     * \brief Construct a UnknownArgument exception
     * \param what the diagnostic message
     */
    UnknownArgument(const std::string& what) : std::invalid_argument(what) {}
};

/**
 * \brief Processes the command-line arguments and modifies accordingly the program settings
 *
 * \param cmdLineArgs the command-line arguments to be processed
 * \param settings the program settings to be modified based upon the arguments received
 *
 * \exception MissingArgument will be emitted if an expected argument is not found during parsing
 * \exception UnknownArgument will be emitted if an argument encountered during parsing is not recognised
 */
void processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        ProgramSettings& settings);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP