#include <iostream>
#include <stack>  // Using STL stack for simplicity
#include <string>
#include <algorithm> // For reverse

using namespace std;

int pre(char opt);
string reverse(const string &input);
string InfixtoPrefix(string infix);
string InfixtoPostfix(string infix);
string PrefixtoInfix(string prefix);
string PostfixtoInfix(string postfix);
string PostfixtoPrefix(string postfix);
string PrefixtoPostfix(string prefix);

int main() {
    int choice;
    string input;

    do {
        cout << "\n========= Expression Converter =========\n";
    cout << "1. Convert Infix to Prefix\n";
    cout << "2. Convert Infix to Postfix\n";
    cout << "3. Convert Prefix to Infix\n";
    cout << "4. Convert Postfix to Infix\n";
    cout << "5. Convert Postfix to Prefix\n";
    cout << "6. Convert Prefix to Postfix\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice (0-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Infix: ";
                cin >> input;
                cout << "The Prefix is: " << InfixtoPrefix(input) << endl;
                break;

            case 2:
                cout << "\nEnter Infix: ";
                cin >> input;
                cout << "The Postfix is: " << InfixtoPostfix(input) << endl;
                break;

            case 3:
                cout << "\nEnter Prefix: ";
                cin >> input;
                cout << "The Infix is: " << PrefixtoInfix(input) << endl;
                break;

            case 4:
                cout << "\nEnter Postfix: ";
                cin >> input;
                cout << "The Infix is: " << PostfixtoInfix(input) << endl;
                break;

            case 5:
                cout << "\nEnter Postfix: ";
                cin >> input;
                cout << "The Prefix is: " << PostfixtoPrefix(input) << endl;
                break;

            case 6:
                cout << "\nEnter Prefix: ";
                cin >> input;
                cout << "The Postfix is: " << PrefixtoPostfix(input) << endl;
                break;

            case 0:
                cout << "Exiting Program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (true);

    return 0;
}

int pre(char opt) {
    if (opt == '^')
        return 3;
    else if (opt == '*' || opt == '/')
        return 2;
    else if (opt == '+' || opt == '-')
        return 1;
    else
        return -1;
}

string reverse(const string &input) {
    string rev = input;
    std::reverse(rev.begin(), rev.end());
    return rev;
}

string InfixtoPostfix(string infix) {
    stack<char> s1;
    string postfix;
    for (char ch : infix) {
        if (isalpha(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s1.push(ch);
        } else if (ch == ')') {
            while (!s1.empty() && s1.top() != '(') {
                postfix += s1.top();
                s1.pop();
            }
            s1.pop();
        } else {
            while (!s1.empty() && pre(s1.top()) >= pre(ch)) {
                postfix += s1.top();
                s1.pop();
            }
            s1.push(ch);
        }
    }
    while (!s1.empty()) {
        postfix += s1.top();
        s1.pop();
    }
    return postfix;
}

string InfixtoPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    string prefix = InfixtoPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string PrefixtoInfix(string prefix) {
    stack<string> s;
    reverse(prefix.begin(), prefix.end());
    for (char ch : prefix) {
        if (isalpha(ch)) {
            s.push(string(1, ch));
        } else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            s.push("(" + op1 + ch + op2 + ")");
        }
    }
    return s.top();
}

string PostfixtoInfix(string postfix) {
    stack<string> s;
    for (char ch : postfix) {
        if (isalpha(ch)) {
            s.push(string(1, ch));
        } else {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            s.push("(" + op1 + ch + op2 + ")");
        }
    }
    return s.top();
}

string PostfixtoPrefix(string postfix) {
    string infix = PostfixtoInfix(postfix);
    return InfixtoPrefix(infix);
}

string PrefixtoPostfix(string prefix) {
    string infix = PrefixtoInfix(prefix);
    return InfixtoPostfix(infix);
}
