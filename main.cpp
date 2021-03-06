#include <iostream>
#include "AncestorTree.h"

using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

int main() {

    family::Tree T("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");

    // displays the tree in a human-friendly format.
    T.display();


    cout << T.relation("Yaakov") << endl;  // prints "father"
    cout << T.relation("Rachel") << endl;  // prints "mother"
    cout << T.relation("Rivka") << endl;  // prints "grandmother"
    cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
    cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
    cout << T.relation("xyz") << endl;  // prints "unrelated"
    cout << T.relation("Yosef") << endl;  // prints "me"

    cout << T.find("mother") << endl;  // prints "Rachel"
    cout << T.find("great-great-grandfather") << endl;  // prints "Avraham"

    try {
        cout << T.find("uncle") << endl;  // throws an exception
    } catch (const exception &ex) {
        cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
    }
    T.remove("Isaac"); // removes Avraham and Terah
    cout << T.relation("Terah") << endl;  // prints "unrelated"
    T.display();




    Context context;
    context.addFilter("reporters", "console");
    context.run();


    return 0;
}
