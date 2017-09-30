"""This file will generate files with 1000 randomly chosen sudoku board from the input file"""

from random import randint

NUMBER_OF_OUTPUT_FILE = 1000
NUMBER_OF_BOARD_IN_OUTPUT_FILE = 1000
INPUT_FILE_OUTPUT_DIR_LIST = [("sudoku_25", "sudoku25"), ("sudoku_35","sudoku35"), ("sudoku_45","sudoku45")]

for inputFileName, outputDirName in INPUT_FILE_OUTPUT_DIR_LIST:
    with open(inputFileName) as sudokuBoards:
        boards = sudokuBoards.readlines();
    for outputFileIndex in range(0, NUMBER_OF_OUTPUT_FILE):
        text = ""
        for j in range(0, NUMBER_OF_BOARD_IN_OUTPUT_FILE): 
            text += boards[randint(0,len(boards))]

        outputFileName = outputDirName + "/" + str(outputFileIndex)
        with open(outputFileName,"w") as outputFile:
            outputFile.write(text)

