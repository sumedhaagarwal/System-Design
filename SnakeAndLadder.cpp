// https://workat.tech/machine-coding/practice/snake-and-ladder-problem-zgtac9lxwntg

#include <bits/stdc++.h>
using namespace std;

map<int,int> snake,ladder,curPos;
int nSnake,nLadder,nPlayers,won,turn,stSnake,stLadder,endSnake,endLadder;
vector<string> players;
string player;

void checkSnake(int playerInd){
	if(snake.find(curPos[playerInd])!=snake.end())
		curPos[playerInd]=snake[curPos[playerInd]];
}

void checkLadder(int playerInd){
	if(ladder.find(curPos[playerInd])!=ladder.end())
		curPos[playerInd]=ladder[curPos[playerInd]];
}

void move(int playerInd){
	int numRolled=1 + (rand() % 6);
	int prevPos=curPos[playerInd];
	if(curPos[playerInd]+numRolled<=100){
		curPos[playerInd]+=numRolled;
		checkSnake(playerInd);
		checkLadder(playerInd);
	}
	if(curPos[playerInd]==100)
		won=playerInd;
	cout<<players[playerInd]<<" rolled a "<<numRolled<<" and moved from "<<prevPos<<" to "<<curPos[playerInd]<<endl;
}

void startGame(){
	turn=0;
	won=-1;
	while(won==-1){
		move(turn);
		turn=(turn+1)%nPlayers;
	}
	cout<<players[won]<<" wins the game"<<endl;
}

void inputSnake(){
	cin>>nSnake;
	for(int i=0;i<nSnake;i++){
		cin>>stSnake>>endSnake;
		snake[stSnake]=endSnake;
	}
}

void inputLadder(){
	cin>>nLadder;
	for(int i=0;i<nLadder;i++){
		cin>>stLadder>>endLadder;
		ladder[stLadder]=endLadder;
	}
}

void inputPlayers(){
	cin>>nPlayers;
	for(int i=0;i<nPlayers;i++){
		cin>>player;
		players.push_back(player);
	}
}

int main() {
	inputSnake();
	inputLadder();
	inputPlayers();
	startGame();
	return 0;
}
