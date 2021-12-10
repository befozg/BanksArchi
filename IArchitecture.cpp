/*
 * Created by Andrey Khmuro, Arina Dolgova and Karen Efremyan
 * as part of the Architecture-1 project
 *
 * December 2021
 * */

#include <string>
#include <pstore.h>
#include <ctime>
#include <vector>

enum AccountType {
    CREDIT,
    DEPOSIT,
    DEBIT
};

enum TransactionStatus {
    SUCCESS,
    PENDING,
    DENIED
};

enum TransactionType {
    CLIENT_TO_CLIENT,
    PERCENTAGE_ACCRUAL_TRANSACTION
};

// TODO: add proper address attributes
class Address {
private:
    std::string countryCode;
    std::string countryName;
    std::string cityName;
    std::string streetName;
    std::string buildingNumber;
    std::string apartmentNumber;
    std::string zipCode;
public:
    // getters & setters;
};

class Passport {
private:
    int series;
    int number;
    DATE issueDate;
    std::string issueAuthority;
    std::string issueDepartmentCode;
public:
    // getters & setters;
};

class Account {
private:
    UUID accountID;
    AccountType type;
    double fundsAmount;
    double percentage;
    std::time_t creationTime;
    bool withdrawPossibility;
    bool replenishPossibility;
    bool transactionPossibility;
public:
    // getters & setters;
};

class CreditAccount: Account {
    UUID creditAccountID;
    double creditLimit;
    double commission;
    bool withdrawPossibility;
    bool replenishPossibility;
    bool transactionPossibility;
public:
    // getters & setters;
};

class DepositAccount: Account {
    UUID depositAccountID;
    std::time_t depositExpirationDate;
public:
    // getters & setters;
};

class DebitAccount: Account {
    UUID debitAccountID;
public:
    // getters & setters;
};

class Client {
    """
    Usual client
    """
private:
    UUID id;
    std::string firstName;
    std::string middleName;
    std::string lastName;
    Address address;
    Passport passport;
    std::vector<UUID> accountsID;
    bool isDoubtful;
public:
    // getters & setters;
};

class Bank {
    """
    Bank - as a side of negotiations and bank operations.
    """
    Account account;
    std::string percentageAccrualPeriod;
public:
    // getters & setters;
};

class BankOperation {
private:
    UUID id;
    Account account;
    double percentage;
    double commission;
public:
    // getters & setters;
};

class Transaction {
private:
    UUID id;
    Account accountFrom;
    Account accountTo;
    TransactionType transactionType;
    std::time_t transactionDate;
    double amount;
    TransactionStatus transactionStatus;
public:
    // getters & setters;
};

class OperationsHistory {
private:
    std::vector<BankOperation> bankOperation;
    std::vector<Transaction> transaction;
public:
    // getters & setters;
};

