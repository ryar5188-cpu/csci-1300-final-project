#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Character.h"
#include "Location.h"
using namespace std;

void startOfGame(string location){
    cout << "----- FANTASY CONGRESS -----" << endl;
    cout << "Current Location: " << location << endl;
    cout << "The hour is late. You sit alone in your tiny apartment, watching the fireworks light up the skies of D.C. in brilliant color.\nSo much for a fun New Year's Eve celebration. You grow bored of watching and look around the minuscule room." << endl;
}

string getValidPlayerName(){ // checks for only spaces, and edge cases like " John     Doe  ". Also limits name to 16 characters just for peace of mind.
string playerName;
    bool validName = false;
    while (!validName) {
        cout << "Welcome to Fantasy Congress! What is your name? (Max 16 characters)" << endl;
        cout << "Name: ";
        getline(cin, playerName);
        int firstNonSpace = -1;
        for (int i = 0; i < playerName.length(); i++) {
            if (playerName[i] != ' ') {
                firstNonSpace = i;
                break;
            }
        }
        int lastNonSpace = -1;
        for (int i = playerName.length() - 1; i >= 0; i--) {
            if (playerName[i] != ' ') {
                lastNonSpace = i;
                break;
            }
        }
        if (firstNonSpace == -1 || lastNonSpace == -1) {
            cout << "Name cannot be empty or only spaces! Try again." << endl;
        } else {
            string cleanName = "";
            for (int i = firstNonSpace; i <= lastNonSpace; i++) {
                if (playerName[i] == ' ') {
                    if (playerName[i + 1] != ' ') {
                        cleanName += playerName[i];
                    }
                } else {
                    cleanName += playerName[i];
                }
            }
            if (cleanName.length() > 16) {
                cout << "That name is too long! (Max 16 characters)" << endl;
            } else {
                return cleanName;
            }
        }
    }
    return "";
}

bool isChoiceDone(const vector<char>& choices, char letter){
    for (int i = 0; i < choices.size(); i++){
        if (choices[i] == letter) {
            return true;
        }
    }
    return false;
}

void bankAccount(double money){
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                  Welcome to D.C. Regional Bank                                                                                                             " << endl;
    cout << "                                                                      Balance: $" << money << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void readingMail(const string& name){ // choose-your-own-adventure style. Can choose whichever option first but must read all of them to proceed.
vector<char> completedMail;
char mailChoice;
bool  isReading = true;
int numMail=3;
while (isReading){
    cout << "--- Mail ---" << endl;
    cout << "There are " << numMail << " items: " << endl;
    if (!isChoiceDone(completedMail, 'A')) {
        cout << "PRESS A TO OPEN: A pamphlet titled 'LUXURIOUS HOMES FOR SALE IN D.C.!! BUY NOW!'" << endl;
    }
    if (!isChoiceDone(completedMail, 'B')){
        cout << "PRESS B TO OPEN: An advertisement that begins with 'VISIT SHADY'S SHOP IN SOUTHTOWN D.C. FOR THE BEST DEALS ON ARTIFACTS!'" << endl;
    }
    if (!isChoiceDone(completedMail, 'C')){
        cout << "PRESS C TO OPEN: A mysterious letter signed by I.B." << endl;
    }
    cout << "Your Choice: ";
    cin >> mailChoice;
    cin.ignore(1000, '\n');
    if (mailChoice >= 'a' && mailChoice <= 'z') {
        mailChoice = mailChoice - 32;
    }
    switch (mailChoice) {
        case 'A':
            if (!isChoiceDone(completedMail, 'A')) {
                cout << "--- PAMPHLET ---" << endl;
                cout << "Hi " << name << ", I'm Agent Bob with LuxuryHomes.com.\nAre YOU rich? Then come down to D.C. Main Square and talk to me about purchasing PRIME real-estate in our glorious capitol Washington D.C.!\nI'll be there every day, rain or shine, so give me a visit! Home prices start at $100,000.\nSee you soon, Bob" << endl;
                completedMail.push_back('A');
                numMail--;
            } else {
                cout << "You've already read that." << endl;
            }
            break;
        case 'B':
            if (!isChoiceDone(completedMail, 'B')) {
                cout << "--- ADVERTISEMENT ---" << endl;
                cout << "What's up, "<< name << ".\nAre you looking for some... extra-ordinary things? You've come to the right place! Find me down one of those alleys south of D.C. Main Square and we'll talk.\n-S" <<endl;
                completedMail.push_back('B');
                numMail--;
            } else {
                cout << "You've already read that." << endl;
            }
            break;
        case 'C':
            if (!isChoiceDone(completedMail, 'C')) {
                cout << "--- MYSTERIOUS LETTER ---" << endl;
                cout << "Hey " << name << ",\nYou don't know me but I've been watching you. You may be of some use to me. Meet me at D.C. Main Square at first light tomorrow morning and let's chat.\nYou will be handsomely rewarded.\n-I.B." << endl;
                completedMail.push_back('C');
                numMail--;
            } else {
                cout << "You've already read that." << endl;
            }
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;  
    }
    if (completedMail.size() == 3){
        cout << "You've read all your mail. You put the stack down and wonder who was behind the cryptic letter.\nAs you have nothing else going on, you decide to meet them tomorrow morning." << endl;
        isReading = false;
    }
}
}

void safeInteraction(string name, double& money){ // The odds of anyone guessing this in one-try is ludicrous so not being able to access bank account temporarily after if you press B first is an acceptable edge case.
string safeGuess;
bool validGuess = false;
cout << "You walk across the room towards your safe. You can rest easy knowing there's a $1,000 nest egg sitting safely inside.\nThe safe sits inconspicuously against the wall farthest from the door. You reach down to put in the code but... Oh No!! You've forgotten it!\nThink, " << name << ", think! You rack your brains in a desperate attempt to recollect anything but come up with nothing, only that it's a four digit code.\nDefeated, you try one of your lucky numbers before heading to bed." << endl;
while(!validGuess){
    cout << "Enter 4-digit code: ";
    cin >> safeGuess;
    cin.ignore(1000, '\n');
    if(safeGuess.length() != 4){ // input validation: don't want anyone wasting their guess on a misinput
        cout << "Invalid input. The code must be exactly 4 digits long. Try again." << endl;
    } else {
        bool isAllNumbers = true;
        for(int i = 0; i < safeGuess.length(); i++){
            if(safeGuess[i] < 48 || safeGuess[i] > 57){
                isAllNumbers = false;
                break;
            }
        }
        if(!isAllNumbers){
            cout << "Invalid input. The code can only contain numbers (0-9). Try again." << endl;
        } else {
            validGuess = true;
        }
        }
}
if(safeGuess == "1935"){
    cout << "The safe clicks open. You grab the $1,000." << endl;
    money += 1000;
} else {
    cout << "Incorect. The safe remains as closed as ever." << endl;
}

}

void beginningApartment(string name, double& money){ //choose-your own adventure A-F that all leads to the same outcome, F after all the other letters.
    char playerStartingChoice;
    vector<char> completedActions;
    bool keepPlaying = true;
    while(keepPlaying){
        cout << "What do you want to do?" << endl;
        if(!isChoiceDone(completedActions,'A')){
        cout << "PRESS A: View your wardrobe" << endl;
        }
        if(!isChoiceDone(completedActions,'B')){
        cout << "PRESS B: Check your bank account" << endl;
        }
        if(!isChoiceDone(completedActions,'C')){
        cout << "PRESS C: Admire your shelf" << endl;
        }
        if(!isChoiceDone(completedActions,'D')){
        cout << "PRESS D: Open your mail" << endl;
        }
        if(!isChoiceDone(completedActions,'E')){
        cout << "PRESS E: Open your safe" << endl;
        }
        cout << "PRESS F: Go to sleep" << endl;       
        cout << "Your Choice: ";
        cin >> playerStartingChoice;
        cin.ignore(1000, '\n');
        if (playerStartingChoice >= 'a' && playerStartingChoice <= 'z') {
            playerStartingChoice = playerStartingChoice - 32;
        }
    switch(playerStartingChoice){
        case 'A':
            if (!isChoiceDone(completedActions, 'A')) {
                    cout << "--- Wardrobe ---" << endl;
                    cout << "Your wardrobe is bare. The few shirts hanging are drab and boring." << endl;
                    completedActions.push_back('A');
                } else {
                    cout << "You've already done that." << endl;
                }
                break;
        case 'B':
            if (!isChoiceDone(completedActions, 'B')){
                bankAccount(money);
                completedActions.push_back('B');
            } else {
                    cout << "You've already done that." << endl;
                }
                break;
        case 'C':
            if (!isChoiceDone(completedActions, 'C')) {
                cout << "--- Shelf ---" << endl;
                cout<< "Your shelf is dusty and empty of any memorabilia." << endl;
                completedActions.push_back('C');
                } else {
                    cout << "You've already done that." << endl;
                }
                break;
        case 'D':
            if (!isChoiceDone(completedActions, 'D')) {
                readingMail(name);
                completedActions.push_back('D');
                } else {
                    cout << "You've already done that." << endl;
                }
                break;
        case 'E':
            if (!isChoiceDone(completedActions, 'E')) {
                cout << "--- Safe ---" << endl;
                safeInteraction(name, money);
                completedActions.push_back('E');
                } else {
                    cout << "You've already done that." << endl;
                }
                break;
        case 'F':
            if (completedActions.size() < 5) {
                cout << "--- Not Yet! ---" << endl;
                cout << "There's a nagging feeling keeping you awake." << endl;
            } else {
                cout << "--- Sleep ---" << endl;
                cout << "You close your blinds and collapse into bed, lamenting at your less-than-ideal situation but excited at the prospect of what this mysterious person could possibly have in store for you." << endl;
                keepPlaying = false;
            }
            break;
        default:
            cout << "Invalid Input. Try again." << endl;
            break;
}
    }

}

void squareBanner(){
    cout << "====================================" << endl;
    cout << "         D.C. MAIN SQUARE" << endl;
    cout << "====================================" << endl;
}

void whiteHouseBanner(){
    cout << "================================" << endl;
    cout << "          WHITE HOUSE" << endl;
    cout << "================================" << endl;
}

void congressBanner(){
    cout << "================================" << endl;
    cout << "           CONGRESS" << endl;
    cout << "================================" << endl;
}

void supremeCourtBanner(){
    cout << "================================" << endl;
    cout << "          SUPREME COURT" << endl;
    cout << "================================" << endl;
}

void crampedApartmentBanner(){
    cout << "================================" << endl;
    cout << "        CRAMPED APARTMENT" << endl;
    cout << "================================" << endl;
}

void shadyAlleyBanner(){
    cout << "================================" << endl;
    cout << "           SHADY ALLEY" << endl;
    cout << "================================" << endl;
}

void choosePrinter(){
    cout << "Choose one:" << endl;
}

void meetingBill(string name){
    char billChoice;
    bool validChoice = false;
    squareBanner();
    cout << "You arrive in the main square of Washington D.C. just as the sun breaks the horizon. You see two men standing several hundred yards away from each other.\nBoth are wearing suits, one sporting a red tie, the other a blue tie. They look like they are both waiting for someone, but they don't seem to be aware of each other.\nYou feel guilty about approaching either man with your unkempt hoodie and jeans, but a burning curiosity pushes you forward.\nJust as you make your first step, the man in the red tie spots you and runs over to greet you, palm outstretched." << endl;
    cout << "Mysterious Man >> 'Ah, you must be " << name << ", yes?'" << endl;
    cout << "Mysterious Man >> 'I've been watching you for quite a while and I think you might be the perfect...candidate.'" << endl;
    while (!validChoice) {
        cout << "PRESS A TO ANSWER: 'Candidate? For what?'" << endl;
        cout << "PRESS B TO ANSWER: 'Who even are you?'" << endl;
        cout << "Your Choice: ";
        cin >> billChoice;
        cin.ignore(1000, '\n');
        if (billChoice >= 'a' && billChoice <= 'z') {
            billChoice = billChoice - 32;
        }
        if (billChoice == 'A') {
            cout << "\n" << name << " >> 'Candidate? For what?'" << endl;
            cout << "Mysterious Man >> 'Not for congress of course! Well...sort of. My name is Bill, but my clientele refer to me as Insider Bill.'" << endl;
            validChoice = true;
        } 
        else if (billChoice == 'B') {
            cout << "\n" << name << " >> 'Who even are you?'" << endl;
            cout << "Mysterious Man >> 'Fair question, " << name << "! My name is Bill, but my clientele refer to me as Insider Bill.'" << endl;
            validChoice = true;
        } 
        else {
            cout << "Invalid input. Please choose A or B." << endl;
        }
    }
    cout << "Insider Bill >> 'That's because I know many things that the vast majority of people aren't privy to.'" << endl;
    cout << "Insider Bill >> 'I know more about the comings and goings of the political higher-ups than most sitting Congresspeople.'" << endl;
    cout << "Insider Bill >> 'This is owed in part to my vast network of spies, consultants, and businesspeople I have obtained over many years to...find things out.'" << endl;
    cout << "Insider Bill >> 'My connections run deeper than you will ever know, " << name << ", and I would like you to join me.'" << endl;
    cout << "Insider Bill >> 'I know you want a new house more than anything. The gentleman in the blue tie over there is Agent Bob. I know him well.'" << endl;
    cout << "Insider Bill >> 'He can get you a house for cheap if you help me. You can buy one with the money you'll make, and trust me, you'll make a lot.'" << endl;
    cout << "Insider Bill >> 'So " << name << ", are you in or out?'" << endl;
    validChoice = false;
    while (!validChoice) {
        cout << "PRESS A TO ANSWER: 'I'm in. Let's do this.'" << endl;
        cout << "PRESS B TO ANSWER: 'I'm sorry, I can't. This sounds illegal.'" << endl;
        cout << "Your Choice: ";
        cin >> billChoice;
        cin.ignore(1000, '\n');
        if (billChoice >= 'a' && billChoice <= 'z') {
            billChoice = billChoice - 32;
        }
        if (billChoice == 'A') {
            cout << "\n" << name << " >> 'I'm in. Let's do this.'" << endl;
            cout << "Insider Bill >> 'Excellent choice, " << name << ". I knew I had a good eye for talent.'" << endl;
            cout << "Insider Bill >> 'Here. I'm giving you a state-of-the-art digital game placard so you can see your important stats and where you are whenever you move around.'" << endl;
            validChoice = true; 
        } 
        else if (billChoice == 'B') {
            cout << "\n" << name << " >> 'I'm sorry, I can't. This sounds illegal.'" << endl;
            cout << "Insider Bill >> 'Shame. Walk away, " << name << ", and forget we ever spoke.'" << endl;
            cout << "Embarrassed, you turn your back on D.C. Main Square. Without Bill's connections, your wild political journey ends before it even begins." << endl;
            cout << "--- GAME OVER ---" << endl;
            exit(0); // Ends program instantly
        } 
        else {
            cout << "Invalid input. Try again." << endl;
        }
    }
}

void gamePlacard(string name, double& money, int& charisma, int& quarter, int& turn, string location){
    string whiteHouseMarker = " ";
    string congressMarker = " ";
    string supremeCourtMarker = " ";
    string squareMarker = " ";
    string apartmentMarker = " ";
    string alleyMarker = " ";
    if (location == "White House") {
        whiteHouseMarker = "*";
    } 
    else if (location == "Congress") {
        congressMarker = "*";
    } 
    else if (location == "Supreme Court") {
        supremeCourtMarker = "*";
    } 
    else if (location == "Square") {
        squareMarker = "*";
    } 
    else if (location == "Cramped Apartment") {
        apartmentMarker = "*";
    } 
    else if (location == "Shady Alley") {
        alleyMarker = "*";
    }
    cout << "Quarter:   " << quarter << "/4       Turn:     " << turn << "/5" << endl;
    cout << "Money: $   " << money << "      Charisma: " << charisma << " points" << endl;
    cout << " " << endl;
    cout << "Map: " << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|WHITE HOUSE|CONGRESS|SUPREME COURT|" << endl;
    cout << "|     " << whiteHouseMarker << "     |   " << congressMarker << "    |      " << supremeCourtMarker << "      |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "            |SQUARE  |CRAMPED APT. |" << endl;
    cout << "            |   " << squareMarker << "    |      " << apartmentMarker << "      |" << endl;
    cout << "            +----------------------+" << endl;
    cout << "                     |SHADY ALLEY  |" << endl;
    cout << "                     |      " << alleyMarker << "      |" << endl;
    cout << "                     +-------------+" << endl;
    cout << "* = You are here" << endl;
    cout << " " << endl;
    cout << "What would you like to do?" << endl;
    cout << " " << endl;

}

void billInstructions(string name, double& money, int& charisma, int& quarter, int& turn, string location){
char choice;
    vector<char> completedInstructions;
    bool isInstructing = true;
    while (isInstructing) { // same system as reading mail. once an option has been selected, it doesn't appear again.
        cout << "--- Talking With Bill ---" << endl;
        if (!isChoiceDone(completedInstructions, 'A')) {
            cout << "PRESS A: 'What do you mean by quarters and turns?'" << endl;
        }
        if (!isChoiceDone(completedInstructions, 'B')) {
            cout << "PRESS B: 'Charisma? What's that?'" << endl;
        }
        if (!isChoiceDone(completedInstructions, 'C')) {
            cout << "PRESS C: 'What items do you need from me?'" << endl;
        }
        cout << "Your Choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');
        if (choice >= 'a' && choice <= 'z') {
            choice = choice - 32;
        }
        switch (choice) {
            case 'A':
                if (!isChoiceDone(completedInstructions, 'A')) {
                    cout << "\n" << name << " >> 'What do you mean by quarters and turns?'" << endl;
                    cout << "Insider Bill >> 'That's pretty simple. I'm giving you a full year (4 quarters) to get the 3 items I need from you! However, this is covert business.'" << endl;
                    cout << "Insider Bill >> 'I can't have you risking blowing my cover, so you're only allowed to move from place to place on your map 5 times per quarter.'" << endl;
                    cout << "Insider Bill >> 'In other words, your turns are your movement, and you get 20 of them before I expect my dues!'" << endl;
                    completedInstructions.push_back('A');
                } else {
                    cout << "You already asked about quarters and turns." << endl;
                }
                break;
            case 'B':
                if (!isChoiceDone(completedInstructions, 'B')) {
                    cout << "\n" << name << " >> 'Charisma? What's that?'" << endl;
                    cout << "Insider Bill >> 'Charisma represents your political influence and charm! You have...well... 0 at the moment.'" << endl;
                    cout << "Insider Bill >> 'You gain charisma by talking to congresspeople and buying suits from my pal Shady, and will use it to gather two of my items!'" << endl;
                    completedInstructions.push_back('B');
                } else {
                    cout << "You already asked about charisma." << endl;
                }
                break;
            case 'C':
                if (!isChoiceDone(completedInstructions, 'C')) {
                    cout << "\n" << name << " >> 'What items do you need from me?'" << endl;
                    cout << "Insider Bill >> 'I need 3 items from you by the end of the year to make sure you're worth my while. You can gather them in any order you please.'" << endl;
                    cout << "Insider Bill >> 'The first is a Signed Presidential Pardon from the President. He'll be at the White House, of course.'" << endl;
                    cout << "Insider Bill >> 'The second is a Lucky Gavel from the Chief Justice at the Supreme Court.'" << endl;
                    cout << "Insider Bill >> 'The third is an Ancient D.C. artifact. I lost it some time ago and need it back.'" << endl;
                    cout << "Insider Bill >> 'Once you give me my items, the game is over!'" << endl; // Buying a house from Agent Bob could be an additional objective in the future.
                    completedInstructions.push_back('C');
                } else {
                    cout << "You already asked about the items you need." << endl;
                }
                break;
            default:
                cout << "Invalid input. Try again." << endl;
                break;
        }
        if (completedInstructions.size() == 3) {
            cout << "Insider Bill >> 'Now that's all understood...best of luck " << name <<"!'" << endl;
            cout << "Insider Bill >> 'I recommend starting at Congress.'" << endl;
            squareBanner();
            gamePlacard(name, money, charisma, quarter, turn, location);
            isInstructing = false;
        }
    }
}

char promptLocationChoice(const Location& currentLoc, bool moveToken){
    if (moveToken) {
        currentLoc.printBanner();
        moveToken = false;
    }
    currentLoc.printInteractionOptions();
    char choice;
        cout << "Your Choice: ";
        cin >> choice;
        cin.ignore(1000, '\n');
        if (choice >= 'a' && choice <= 'z') {
        choice = choice - 32;
    }
    return choice;
}


int main(){
    string playerName = getValidPlayerName(); //initializing base variables
    double money = 0.00;
    int charisma = 0;
    int quarter = 1;
    int turn = 0;
    
    
    Item Pardon("Signed Presidential Pardon", 0, 50, false, false); //setting up items
    Item Gavel("Lucky Gavel", 0, 100, false, false);
    Item Artifact("Ancient D.C. Artifact", 1000, 0, false, false);
    

    Character Rick("Congress", "Congressperson Rick", "I just doubled your money for being an upstanding citizen.", false); //setting up Characters
    Character Jessica("Congress", "Congressperson Jessica", "I'm giving you $500 because Bill supported my campaign last year!", false);
    Character Seth("Congress", "Congressperson Seth", "Here's your safe code, 1935. That's the original safemaker's birthday.", false);
    Character President("White House", "President", "Of course! Your charm and political sway completely convince me!", false);
    Character ChiefJustice("Supreme Court", "Chief Justice", "Your legal and structural arguments are uniquely fascinating. Very well, you may carry my Lucky Gavel!", false);
    Character Shady("Shady Alley", "Shady", "Looking clean! That blue tie makes you look like a trustworthy bureaucrat.", false);
    Character PowerShady("Shady Alley", "Shady", "Now THAT is a power suit. Red means business around here.", false);


    Location currentLoc("Cramped Apartment"); // current location


    startOfGame(currentLoc.getName()); // sending current location to startOfGame function
    beginningApartment(playerName, money);


    currentLoc = Location("Square"); //Setting up how to play
    meetingBill(playerName);
    gamePlacard(playerName, money, charisma, quarter, turn, currentLoc.getName());
    billInstructions(playerName, money, charisma, quarter, turn, currentLoc.getName());


    bool moveToken = true;
    bool gameRunning = true;

// WIN CONDITION FLAGS
    vector<Item> items = {};
    while (gameRunning) {
        if (turn >= 5) {
            turn = 0;
            quarter++;
            if (quarter > 4) {
                cout << "\n--- GAME OVER ---" << endl;
                cout << "Insider Bill >> 'Time's up, " << playerName << "! You couldn't secure my items before the year ended. Deal's off. Forever.'" << endl;
                gameRunning = false;
                break;
            }
            cout << "NEW QUARTER! Welcome to Quarter " << quarter << "!" << endl;
        }
        if (moveToken) { // If moveToken is true, the player has moved and their dashboard should be updated.
            gamePlacard(playerName, money, charisma, quarter, turn, currentLoc.getName());
        }
        string locName = currentLoc.getName();

//Main square logic

        if (locName == "Square") {
            char choice = promptLocationChoice(currentLoc, moveToken);
            if (choice == 'A') {
            if (Pardon.getAcquired() && Gavel.getAcquired() && Artifact.getAcquired()) {
                cout << "Insider Bill >> 'I don't believe it! You actually managed to gather all three items?'" << endl;
                cout << "Insider Bill >> 'Well...as promised, Agent Bob here is going to hook you up with a massive mansion in the D.C. suburbs.'" << endl;
                cout << "Insider Bill >> 'Pleasure doing business with you, " << playerName << ".'" << endl;
                cout << "\n--- YOU WIN! ---" << endl;
                gameRunning = false;
            } else {
                cout << "Insider Bill >> 'I need my items, " << playerName << "! Get back out there!'" << endl;
                }
                moveToken = false;
                    } 
            else if (choice == 'B') {
                if (Pardon.getAcquired() && Gavel.getAcquired() && Gavel.getAcquired()) {
                    cout << "Agent Bob >> 'Insider Bill told me you got everything! Let's get your new house keys!'" << endl;
            } else {
                cout << "Agent Bob >> 'Hey " << playerName << "! I can get you a house once you fulfill Insider Bill's requirements!'" << endl;
                }
                moveToken = false;
            } 
            else if (choice == 'C') {
                currentLoc = Location("Congress");
                turn++;
                moveToken = true;
            } 
            else if (choice == 'D') {
                currentLoc = Location("Cramped Apartment");
                turn++;
                moveToken = true;
            }
            else {
                cout << "Invalid input for this location. Try again." << endl;
            }
        }


//Congress Logic
    else if (locName == "Congress") {
        char choice = promptLocationChoice(currentLoc, moveToken);
        if (choice == 'A') {
            cout << playerName << " >> 'Hey Rick, do you have something for me?'" << endl;
            if (!Rick.interacted) money *= 2; // Doubled only once
                Rick.talkToChar();
        } else if (choice == 'B') {
        cout << playerName << " >> 'Hey Jessica, do you have something for me?'" << endl;
        if (!Jessica.interacted) money += 500; // given only once
            Jessica.talkToChar();
        } else if (choice == 'C'){
                cout << playerName << " >> 'Hi Seth, do you have something for me?'" << endl;
                Seth.talkToChar();
        } else if (choice == 'D'){
                currentLoc = Location("Supreme Court");
                turn++;
                moveToken = true;
        } else if(choice == 'E'){
                currentLoc = Location("White House");
                turn++;
                moveToken = true;
        } else if(choice == 'F'){
                currentLoc = Location("Square");
                turn++;
                moveToken = true;
        } else cout << "Invalid input for this location. Try again." << endl;
    }
        
//White house logic
        else if (locName == "White House") {
            char choice = promptLocationChoice(currentLoc, moveToken);
            if (choice == 'A') {
                if (Pardon.getAcquired()) {
                    cout << "President >> 'I already granted you a pardon! Go use it!'" << endl;
                } else {
                    cout << playerName << " >> 'I need a signed pardon, Mr. President.'" << endl;
                    if (Pardon.attemptAcquire(money, charisma)) {
                        charisma -= Pardon.getCharismaCost();
                        President.talkToChar();
                        cout << "[!] You acquired: " << Pardon.getName() << endl;
                    } else {
                        cout << "President >> 'I can't do that. Come back when you have at least " << Pardon.getCharismaCost() << " charisma.'" << endl;
                    }
                }
            } 
            else if (choice == 'B') {
                currentLoc = Location("Congress");
                turn++;
                moveToken = true;
            } else cout << "Invalid input for this location. Try again." << endl;
        }
        
// Supreme court logic
        else if (locName == "Supreme Court") {
            char choice = promptLocationChoice(currentLoc, moveToken);
            if (choice == 'A') {
                cout << "Chief Justice >> 'Welcome to the highest court in all the land.'" << endl;
            } 
            else if (choice == 'B') {
                if (Gavel.getAcquired()) {
                    cout << "Chief Justice >> 'You already argued your way into acquiring my Lucky Gavel.'" << endl;
                } else {
                    if (Gavel.attemptAcquire(money, charisma)) {
                        charisma -= Gavel.getCharismaCost();
                        ChiefJustice.talkToChar();
                        cout << "[!] You acquired: " << Gavel.getName() << endl;
                    } else {
                        cout << "Chief Justice >> 'Objection! Come back when you possess at least " << Gavel.getCharismaCost() << " Charisma.'" << endl;
                    }
                }
            } 
            else if (choice == 'C') {
                currentLoc = Location("Cramped Apartment");
                turn++;
                moveToken = true;
            } 
            else if (choice == 'D') {
                currentLoc = Location("Congress");
                turn++;
                moveToken = true;
            } else cout << "Invalid input for this location. Try again." << endl;
        }
        
// Apt logic
        else if (locName == "Cramped Apartment") {
            char choice = promptLocationChoice(currentLoc, moveToken);
            if (choice == 'A') {
                cout << "--- Wardrobe ---" << endl;
                cout << "Your wardrobe is expanding. Buy suits from Shady's Shop to bolster your charisma!" << endl;
            } 
            else if (choice == 'B') {
                cout << "--- Shelf ---" << endl;
                if (Artifact.getAcquired()) {
                    cout << "The Ancient D.C. artifact sits proudly on your dusty shelf. Somehow the shelf is dustier than ever." << endl;
                } else {
                    cout << "Your shelf is dusty and empty of any memorabilia." << endl;
                }
            } 
            else if (choice == 'C') {
                safeInteraction(playerName, money);
            } 
            else if (choice == 'D') {
                currentLoc = Location("Shady Alley");
                turn++;
                moveToken = true;
            } 
            else if (choice == 'E') {
                currentLoc = Location("Square");
                turn++;
                moveToken = true;
            } 
            else if (choice == 'F') {
                currentLoc = Location("Supreme Court");
                turn++;
                moveToken = true;
            } else cout << "Invalid input for this location. Try again." << endl;
        }
        
// Shady alley logic
        else if (locName == "Shady Alley") {
            char choice = promptLocationChoice(currentLoc, moveToken);
            if (choice == 'A') {
                if (money >= 100) {
                    money -= 100;
                    charisma += 25;
                    Shady.talkToChar(); // Dialogue resets 'interacted' naturally so we can ignore the boolean here if they want to buy multiple suits!
                    cout << "[+] Paid $100. Gained 25 Charisma." << endl;
                } else {
                    cout << "Shady >> 'No good. You'll need $100 for this one.'" << endl;
                }
            } 
            else if (choice == 'B') {
                if (money >= 500) {
                    money -= 500;
                    charisma += 150;
                    PowerShady.talkToChar(); 
                    cout << "[+] Paid $500. Gained 150 Charisma." << endl;
                } else {
                    cout << "Shady >> 'You need $500 for this one.'" << endl;
                }
            } 
            else if (choice == 'C') {
                if (Artifact.getAcquired()) {
                    cout << "Shady >> 'I already sold you the artifact!'" << endl;
                } else {
                    if (Artifact.attemptAcquire(money, charisma)) {
                        money -= Artifact.getMonetaryCost();
                        cout << "Shady >> 'Ah, the engraved rock piece Bill lost. Take it.'" << endl;
                        cout << "[!] You acquired: " << Artifact.getName() << endl;
                    } else {
                        cout << "Shady >> 'Artifacts aren't cheap. I need $" << Artifact.getMonetaryCost() << " for this.'" << endl;
                    }
                }
            } 
            else if (choice == 'D') {
                currentLoc = Location("Cramped Apartment");
                turn++;
                moveToken = true;
            } else cout << "Invalid input for this location. Try again." << endl;
        }
    }
    return 0;
    }
