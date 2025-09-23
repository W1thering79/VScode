#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

#include "HotDogStandsClass.h"
#include "TransactionsClass.h"

using namespace std;

const string   HOTDOG_STANDS_FILE_NAME_STR = "InfoHotDogStands.txt";
const string   TRANSACTIONS_FILE_NAME_STR  = "InfoHotDogStandsTransactions.txt";
const string   GLOBAL_SOLD__FILE_NAME_STR  = "InfoGlobalSold.txt";

ostream& operator<<(ostream& leftSideOutputStream, const HotDogStandsClass& hotDogStandObj);

ostream& operator<<(ostream& leftSideOutputStream, const TransactionsClass& transactionsObj);

void CheckFileStreamOpen(string globalSoldFileNameStr, ifstream& inFile);

void ReadInFromGlobalSoldFile(string globalSoldFileNameStr);

void ReadInFromHotDogStandsFileTo
(string hotDogStandsFileNameStr, HotDogStandsClass*& hotDogStandsAry,
  unsigned& standsLineCount);

void ReadInFromTransactionsFileTo
(string transactionsFileNameStr, TransactionsClass*& transactionsAry, unsigned& transactionsLineCount);

void displayStands(HotDogStandsClass* hotDogStandsAry, unsigned totalNoHotDogStandsUns);

unsigned getMatchingHotDogStandIndexUns
(HotDogStandsClass* hotDogStandsAry, unsigned totalNoHotDogStandsUns,
 TransactionsClass* transactionsAry, unsigned transactonsNoUns);

void processTransactions
(HotDogStandsClass*& hotDogStandsAry, unsigned totalNoHotDogStandsUns,
  TransactionsClass* transactionsAry, unsigned totalNoTransactonsUns);

void UpdateHotDogStandsFile
(string   hotDogStandsFileNameStr, HotDogStandsClass* hotDogStandsAry,
 unsigned totalNoHotDogStandsUns);

void UpdateGlobalSoldFile(string globalSoldFileNameStr);

int main() {

    cout << setprecision(2) << fixed << showpoint;

    HotDogStandsClass* hotDogStandsAry = nullptr;
    unsigned          hotDogStandsCountUns;
    TransactionsClass* transactionsAry = nullptr;
    unsigned          transactonsCountUns;

    ReadInFromGlobalSoldFile(GLOBAL_SOLD__FILE_NAME_STR);
    ReadInFromHotDogStandsFileTo
    (HOTDOG_STANDS_FILE_NAME_STR, hotDogStandsAry, hotDogStandsCountUns);
    ReadInFromTransactionsFileTo
    (TRANSACTIONS_FILE_NAME_STR, transactionsAry, transactonsCountUns);

    cout << "Initial states of stands:" << endl;
    cout << "=========================" << endl << endl;
    displayStands(hotDogStandsAry, hotDogStandsCountUns);

    cout << "Process Transactions:" << endl;
    cout << "=====================" << endl << endl;
    processTransactions(hotDogStandsAry, hotDogStandsCountUns, transactionsAry, transactonsCountUns);

    cout << "Final states of stands:" << endl;
    cout << "=======================" << endl << endl;
    displayStands(hotDogStandsAry, hotDogStandsCountUns);

    UpdateHotDogStandsFile(HOTDOG_STANDS_FILE_NAME_STR, hotDogStandsAry, hotDogStandsCountUns);
    UpdateGlobalSoldFile(GLOBAL_SOLD__FILE_NAME_STR);

    cout << "Please press enter key once or twice to end..."; cin.ignore(); cin.get();

    exit(EXIT_SUCCESS);

}

ostream& operator<<(ostream& leftSideOutputStream, const HotDogStandsClass& hotDogStandObj) {
  leftSideOutputStream<<"StandID: "<<hotDogStandObj.getIdStr()<<endl;
  leftSideOutputStream<<"Address: "<<hotDogStandObj.getAddressStr()<<endl;
  leftSideOutputStream<<"Price: $"<<hotDogStandObj.getPriceFl()<<endl;
  leftSideOutputStream<<"Stand Sold: "<<hotDogStandObj.getSoldAmountUns()<<" at $"<<hotDogStandObj.getPriceFl()<<" each."<<endl;
  leftSideOutputStream<<"Inventory: "<<hotDogStandObj.getInventoryAmountUns()<<endl;
  return leftSideOutputStream;
}

ostream& operator<<(ostream& leftSideOutputStream, const TransactionsClass& transactionsObj) {
  leftSideOutputStream<<"Transaction Stand ID: "<<transactionsObj.getIdentificationStr()<<endl;
  leftSideOutputStream<<"Transaction ID: "<<transactionsObj.getTransactionIdStr()<<endl;
  leftSideOutputStream<<"Transaction Argument: "<<transactionsObj.getTransactionArgumentUns()<<endl;
  return leftSideOutputStream;
}

void CheckFileStreamOpen(string globalSoldFileNameStr, ifstream &inFile) {
  if (inFile.fail()) {
    cout << "File " << globalSoldFileNameStr << "could not be opened !" << endl;
    cout << endl << "Press the enter key once or twice to continue..." << endl; cin.ignore(); cin.get();
    exit(EXIT_FAILURE);
  }
}

void ReadInFromGlobalSoldFile(string globalSoldFileNameStr) {

  ifstream inFile(globalSoldFileNameStr);
  CheckFileStreamOpen(globalSoldFileNameStr,inFile);

  inFile>>HotDogStandsClass::globalSoldCountUns;

  inFile.close();
}

void ReadInFromHotDogStandsFileTo
(string hotDogStandsFileNameStr, HotDogStandsClass*& hotDogStandsAry,
  unsigned& hotDogStandsCountUns) {

  ifstream inFile(hotDogStandsFileNameStr);
  CheckFileStreamOpen(hotDogStandsFileNameStr, inFile);

  string lineInFileBufferStr;

  // Count the number of lines in the file
  hotDogStandsCountUns = 0;
  while (getline(inFile, lineInFileBufferStr))
    ++hotDogStandsCountUns;

  hotDogStandsAry = new HotDogStandsClass[hotDogStandsCountUns];

  inFile.clear(); inFile.seekg(0, ios::beg);
  string inputStr;
  constexpr char COMMA_DELIMTER_CHAR = ',';

  // for each line read from the file
  for (unsigned lineCount = 0; lineCount < hotDogStandsCountUns; ++lineCount) {
    getline(inFile, lineInFileBufferStr);
    istringstream isStringStream(lineInFileBufferStr);

    // read everything up to the comma delimeter
    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    hotDogStandsAry[lineCount].setIdStr(inputStr);

    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    hotDogStandsAry[lineCount].setAddressStr(inputStr);

    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    hotDogStandsAry[lineCount].setPriceFl(stof(inputStr));

    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    hotDogStandsAry[lineCount].setSoldAmountUns(stoi(inputStr));

    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    hotDogStandsAry[lineCount].setInventoryAmountUns(stoi(inputStr));

  }// for

  inFile.close();
}

void ReadInFromTransactionsFileTo
(string transactionsFileNameStr, TransactionsClass*& transactionsAry, unsigned& transactionsLineCount) {

  ifstream inFile(transactionsFileNameStr);
  CheckFileStreamOpen(transactionsFileNameStr, inFile);

  string lineInFileBufferStr;

  // Count the number of lines in the transactions file
  transactionsLineCount = 0;
  while (getline(inFile, lineInFileBufferStr))
    ++transactionsLineCount;

  transactionsAry = new TransactionsClass[transactionsLineCount];

  inFile.clear(); inFile.seekg(0, ios::beg);
  string inputStr;
  constexpr char COMMA_DELIMTER_CHAR = ',';

  for (unsigned lineCount = 0; lineCount < transactionsLineCount; ++lineCount) {
    getline(inFile, lineInFileBufferStr);
    istringstream isStringStream(lineInFileBufferStr);

    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    transactionsAry[lineCount].setIdentificationStr(inputStr);

    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    transactionsAry[lineCount].setTransactionIdStr(inputStr);

    getline(isStringStream, inputStr, COMMA_DELIMTER_CHAR);
    transactionsAry[lineCount].setTransactionArgumentUns(stoi(inputStr));
    
  }

  inFile.close();
}

void displayStands(HotDogStandsClass* hotDogStandsAry, unsigned totalNoHotDogStandsUns) {

  for (unsigned i=0;i<totalNoHotDogStandsUns;++i)
  {
    cout<<"Stand ID: "<<hotDogStandsAry[i].getIdStr()<<endl;
    cout<<"Address: "<<hotDogStandsAry[i].getAddressStr()<<endl;
    cout<<"Hotdog Price: "<<setprecision(2)<<hotDogStandsAry[i].getPriceFl()<<endl;
    cout<<"Inventory Left: "<<hotDogStandsAry[i].getInventoryAmountUns()<<endl;
    cout<<"Sold Amount: "<<hotDogStandsAry[i].getSoldAmountUns()<<endl;

  }
  
  cout << endl << "Global Sold : " << HotDogStandsClass::globalSoldCountUns << endl << endl;
  cout << "Please press enter key once or twice to continue..."; cin.ignore(); cin.get();
  cout << endl << endl;
}

unsigned getMatchingHotDogStandIndexUns
(HotDogStandsClass* hotDogStandsAry, unsigned totalNoHotDogStandsUns,
  TransactionsClass* transactionsAry, unsigned transactonsCountUns) {
  for (unsigned seekIndex = 0; seekIndex < totalNoHotDogStandsUns; ++seekIndex)
    if (hotDogStandsAry[seekIndex].getIdStr() == transactionsAry[transactonsCountUns].getIdentificationStr())
      return(seekIndex);
      return unsigned(-1);
}

void processTransaction(TransactionsClass transactionObj, HotDogStandsClass& hotDogStandObj) {
  if (transactionObj.getTransactionIdStr() == "stock inventory") 
  {
      unsigned stockAmount=transactionObj.getTransactionArgumentUns();
      hotDogStandObj.stockInventoryAmountUns(stockAmount);
  }
  else if (transactionObj.getTransactionIdStr() == "buy")
  {
      unsigned buyAmount=transactionObj.getTransactionArgumentUns();
      hotDogStandObj.hotDogsBuyUns(buyAmount);
  }

};

void processTransactions
(HotDogStandsClass*& hotDogStandsAry, unsigned totalNoHotDogStandsUns,
  TransactionsClass* transactionsAry, unsigned transactonsCountUns) {

  for (unsigned transactionNoUns = 0; transactionNoUns < transactonsCountUns; ++transactionNoUns) {
    //Find correct stand
    unsigned hotDogStandIndexUns =
      getMatchingHotDogStandIndexUns(hotDogStandsAry, totalNoHotDogStandsUns,
        transactionsAry, transactionNoUns);
    cout << "-----------------------------" << endl << endl;
    cout << "HotDog Stand Current Status :" << endl << endl;
    cout << hotDogStandsAry[hotDogStandIndexUns] << endl;
    cout << "Transaction: " << endl << endl;
    cout << transactionsAry[transactionNoUns] << endl;
    processTransaction(transactionsAry[transactionNoUns], hotDogStandsAry[hotDogStandIndexUns]);
    cout << "HotDog Stand Status After Transaction :" << endl << endl;
    cout << hotDogStandsAry[hotDogStandIndexUns] << endl << endl;
    cout << "Global Sold : " << HotDogStandsClass::globalSoldCountUns << endl << endl;
    cout << "Please press enter key once or twice to continue..."; cin.ignore(); cin.get();
  }
}

void UpdateHotDogStandsFile
(string   hotDogStandsFileNameStr, HotDogStandsClass* hotDogStandsAry,
  unsigned totalNoHotDogStandsUns) {

  ofstream outFile(hotDogStandsFileNameStr);

  for (unsigned writeIndex = 0; writeIndex < totalNoHotDogStandsUns; ++writeIndex)
    outFile <<
    hotDogStandsAry[writeIndex].getIdStr()              << "," <<
    hotDogStandsAry[writeIndex].getAddressStr()         << "," <<
    hotDogStandsAry[writeIndex].getPriceFl()            << "," <<
    hotDogStandsAry[writeIndex].getInventoryAmountUns() << "," <<
    hotDogStandsAry[writeIndex].getSoldAmountUns()      << endl;

  outFile.close();
};

void UpdateGlobalSoldFile(string globalSoldFileNameStr) {

  ofstream outFile(globalSoldFileNameStr);
  outFile << HotDogStandsClass::globalSoldCountUns << endl;

};








