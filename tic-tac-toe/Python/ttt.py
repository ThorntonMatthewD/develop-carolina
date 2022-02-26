class Player():

    def __init__(self, icon, playerNum):
        self.icon = icon
        self.wins = 0
        self.playreNum = playerNum


    def incWin(self):
        self.wins += 1


class Board():

    def __init__(self):
        self.boardTiles = []
        self.resetBoard()


    def addIcon(self, icon):
        isPlaced = False

        while not isPlaced:
            self.displayBoard()

            try:
                tile_num = int(input("Enter the tile you would like to place your next marker (0-8):\n"))
                
                if self.checkPlacement(tile_num):
                    self.boardTiles[tile_num] = icon
                    isPlaced = True

            except ValueError:
                print("Enter an integer from 1-9.\n")


        self.displayBoard()


    def checkPlacement(self, idx):
        if idx in range(0, 9):
            if self.boardTiles[idx] == '-':
                return True
            else:
                print("There is already a marker there. Please choose another tile.")
                return False
        else:
            print("Choose a tile 0-8.")
            return False


    def checkForWin(self):
        #diagonal win check
        if self.boardTiles[4] != '-':
            if self.boardTiles[0] == self.boardTiles[4] == self.boardTiles[8]:
                return True
            elif self.boardTiles[2] == self.boardTiles[4] == self.boardTiles[6]:
                return True
            else:
                #No win yet!
                pass

        #horizontal win check
        for t in (1, 4, 7):
            if self.boardTiles[t-1] == self.boardTiles[t] == self.boardTiles[t+1] != '-':
                return True
            else:
                #Still no win!
                pass

        #vertical win check
        for t in (3, 4, 5):
            if self.boardTiles[t-3] == self.boardTiles[t] == self.boardTiles[t+3] != '-':
                return True
            else:
                #No win at all! Shame!
                return False


    def resetBoard(self):
        self.boardTiles = ['-' for i in range(0,9)]


    def displayBoard(self):
        board = "-------------\n"

        for t in range(0, len(self.boardTiles), 3):
            board += f"| {self.boardTiles[t]} | {self.boardTiles[t+1]} | {self.boardTiles[t+2]} |\n"
            board += "-------------\n"

        print(board)
            

class TicTacToe():

    def __init__(self):
        self.players = [Player("X", 1), Player("O", 2)]
        self.gameBoard = Board()

        self.keepPlaying = True
        self.turnNum = 0
        self.currPlayer = 0

    def playGame(self):
        while self.keepPlaying:
            self.gameBoard.addIcon(self.players[self.currPlayer].icon)
            self.turnNum += 1

            if self.turnNum >= 5:
                if self.gameBoard.checkForWin():
                    self.players[self.currPlayer].incWin()
                    print(f"Woohoo! Player {self.players[self.currPlayer].playreNum} wins!")
                    self.askKeepPlaying()
                elif self.turnNum == 9:
                    print("Looks like we have a tie on our hands. In others words, you both lose! Yay!")
                    self.askKeepPlaying()
                else:
                    pass

            self.switchCurrPlayer()


    def switchCurrPlayer(self):
        if self.currPlayer == 0:
            self.currPlayer = 1
        else:
            self.currPlayer = 0


    def askKeepPlaying(self):
        answer = input("Want to keep playing? Press y, or type literally anything else to stop playing: ")
        if answer.lower() != "y":
            self.keepPlaying = False
        else:
            self.resetGame()


    def resetGame(self):
        self.gameBoard.resetBoard()
        self.currPlayer = 0


if __name__ == "__main__":
    game_engine = TicTacToe()
    game_engine.playGame()
