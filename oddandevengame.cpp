#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>

struct user
{
int user;
int oddevenchoice;
int toss;
int batbowlchoice;
int score;
int innings;
};

int score(user player,int prevscore)
{
int bot,player1,score1=0;
cout<<"\n"<<setw(42)<<"You\tBot";
do
{
	randomize();
	bot=random(7);
	do
		{
		cout<<"\n\t\t\t\t   ";
		cin>>player1;
		}
	while(player1<0||player1>6);
	cout<<setw(41)<<bot;
		if(bot!=player1&&player.user==0) // To add user's score while it's  not out
			score1+=player1;
		else if(bot!=player1&&player.user==1) // To add bot's score while it's not out
			score1+=bot;
}
while((player.innings==1&&bot!=player1)||(player.innings==2&&bot!=player1&&score1<=prevscore));
return score1;
}

void game(user player,user bot)
{
cout<<"\nInstructions for batting : ";
cout<<"\nEnter a number between 0 to 6 to score runs";
cout<<"\nIf the bot enters the same number as you do , you're dismissed";
cout<<"\n\nInstructions for bowling : ";
cout<<"\nThe bot enters a number between 0 to 6 to score runs";
cout<<"\nIf you enter the same number as the bot , the bot's dismissed";
if(player.batbowlchoice==0||bot.batbowlchoice==1) // Conditions for the user to be batting
	{
	cout<<"\n\n"<<setw(52)<<" ! Your turn to bat ! \n";
	player.innings=1;
	player.score=score(player,0); // To calculate user's score in the first innings
	cout<<"\n\n Your score is : "<<player.score;
	cout<<"\n\n"<<setw(52)<<" ! Your turn to bowl ! \n";
	bot.innings=2;
	bot.score=score(bot,player.score); //
	cout<<"\n\n Bot's score is : "<<bot.score;
	}
else if(player.batbowlchoice==1||bot.batbowlchoice==0) // Conditions for the user to be batting
	{
	cout<<"\n\n"<<setw(52)<<" ! Your turn to bowl ! \n";
	bot.innings=1;
	bot.score=score(bot,0); // To calculate bot's score in the first innings
	cout<<"\n\n Bot's score is : "<<bot.score;
	cout<<"\n\n"<<setw(52)<<" ! Your turn to bat ! \n";
	player.innings=2;
	player.score=score(player,bot.score); //
	cout<<"\n\n Your score is : "<<player.score;
	}
if(player.score>bot.score)
	cout<<"\n\n"<<setw(45)<<" !! YOU WIN !!";
else if(bot.score>player.score)
	cout<<"\n\n"<<setw(47)<<" !! YOU LOOSE !!";
else if(bot.score==player.score)
	cout<<"\n\n"<<setw(48)<<" !! IT'S A DRAW !!";
}

void main()
{
clrscr();
user bot;
user player;
bot.user=1;
player.user=0;
cout<<endl<<setw(44)<<"ODD EVEN";

do
{
	cout<<"\n\n What do you choose odd or even [ 0 - Even || 1 - Odd ] : ";
	cin>>player.oddevenchoice;
}
while(player.oddevenchoice!=0&&player.oddevenchoice!=1);

cout<<"\n"<<setw(46)<<"!!TOSS!!\n\n";

do
{
	cout<<" Enter a number from 0 to 6 for toss  : ";
	cin>>player.toss; // User's toss choice
}
while(player.toss>6||player.toss<0);

randomize();
bot.toss=random(7); // Bot's toss choice chosen randomly from 0 to 6

cout<<"\n The bot enters : "<<bot.toss<<endl;
int tossresult=player.toss+bot.toss; // Sum of toss choice's of bot and user ie tossresult result

if((tossresult%2==0&&player.oddevenchoice==0)||(tossresult%2==1&&player.oddevenchoice==1)) // To check if user wins the toss
	{
	cout<<"\n You've won the toss !! \n";
	cout<<"\n What do you choose batting or bowling [ 0 - Bat || 1 - Bowl ] : ";
	cin>>player.batbowlchoice;
	if(player.batbowlchoice==0)
		game(player,bot); // Specifies to the game function that the user is batting first
	else if(player.batbowlchoice==1)
		game(player,bot); // Specifies to the game function that the user is bowling first
	}
else
	{
	cout<<"\n You've lost the toss !! \n";
	randomize();
	bot.batbowlchoice=random(2); // Bot's choice to bat or bowl
	if(bot.batbowlchoice==0)
		{
		cout<<"\n The bot chooses to bat \n";
		game(player,bot); // Specifies to the game function that the bot is batting first
		}
	else if(bot.batbowlchoice==1)
		{
		cout<<"\n The bot chooses to bowl \n";
		game(player,bot); // Specifies to the game function that the bot is bowling first
		}
	}
getch();
}

