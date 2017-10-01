#!/usr/bin/env python3

import os
import random
import subprocess
import sys
from time import gmtime, strftime


SOURCE_CODE = ["src/Sudoku.h", "src/Sudoku.cpp", "src/Algorithm.h", "src/Algorithm.cpp" , "src/FileHandler.h", "src/FileHandler.cpp", "src/main.cpp"]
SUDOKU = {"25": "boards/sudoku25", "35": "boards/sudoku35", "45": "boards/sudoku45"}

def compile(output, defines, library = "", flags =""):
    command =["g++", "-D", defines, "-o", "bin/" + output] 
    if library != "":
        command.extend(library)
    if flags != "":
        command.extend(flags)
    command.extend(SOURCE_CODE)
    print(' '.join(command))
    p = subprocess.Popen(command)
    p.communicate()
    #  print("Compile Finished")

def run(exe, args =""):
    command = [exe]
    if type(args) is str and args != "":
        command.append(args)
    elif type(args) is list and len(args) != 0:
        command.extend(args)
    print(' '.join(command))
    print('=====================================================================\n')
    p = subprocess.Popen(command,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
    output= p.communicate()
    print('\n=====================================================================')
    print(revertText(output[1]))
    print(revertText(output[0]))
    return output


def pickRandom(directory):
    return directory  + "/" + random.choice(os.listdir(directory))

def createLogName(sudokuSet):
    return strftime("%Y-%m-%d-%H-%M-%S", gmtime()) + os.path.basename(sudokuSet) + "_" + ".log"

def write(fileName, text):
    textFile = open(fileName, "w")
    textFile.write(text)
    textFile.close()

def revertText(text):
    return text.decode("UTF-8")
    #  return text.replace('\\n','\n').replace('\\b','\b')

def default(args):
    compile("SudokuSolver","DEFAULT")
    run("bin/SudokuSolver", pickRandom(SUDOKU[args[0]]))

def debug(args):
    compile("SudokuSolver_d","DEBUG")
    run("bin/SudokuSolver_d", "boards/boards_debug/" + args[0])

def cache(args):
    compile("SudokuSolver_c","CACHE")
    sudokuSet = pickRandom(SUDOKU[args[0]])
    logName = createLogName(sudokuSet) 
    output = run("valgrind", [ "--tool=cachegrind", "--branch-sim=yes", "--cachegrind-out-file=log/cachegrind/" + logName, "bin/SudokuSolver_c", sudokuSet])
    write("log/cachegrind/" + logName + ".summary", revertText(output[1]))

def time(args):
    compile("SudokuSolver_t","TIME")
    sudokuSet = pickRandom(SUDOKU[args[0]])
    run("bin/SudokuSolver_t", pickRandom(SUDOKU[args[0]]))

def val(args):
    compile("SudokuSolver_v","PROFILE_VALGRIND", "-g")
    sudokuSet = pickRandom(SUDOKU[args[0]])
    run("bin/SudokuSolver_v", pickRandom(SUDOKU[args[0]]))

def gperf(args):
    compile("SudokuSolver_g","PROFILE_GPERF", "-gp")
    sudokuSet = pickRandom(SUDOKU[args[0]])
    run("bin/SudokuSolver_g", pickRandom(SUDOKU[args[0]]))



sys.argv.pop(0)
command = sys.argv.pop(0)
if command == "run":
    default(sys.argv)
elif command == "debug":
    debug(sys.argv)
elif command == "cache":
    cache(sys.argv)
elif command == "time":
    time(sys.argv)
elif command == "gperf":
    gperf(sys.argv)
elif command == "val":
    val(sys.argv)


