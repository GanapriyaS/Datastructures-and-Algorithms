/*
    link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

    ref for string::npos: https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using concatenation
*/
bool check_rotated(string a, string b) {
    // for eg.: a="AACD" b="ACDA"
    if(a.length() != b.length()) return false;
    string temp = a+a;
    // a="AACDAACD"
    // now string b must be sub-string in a hence.

    // find will return 0th based index from where the substring will start.
    return (temp.find(b) != string::npos) ;
}



// ----------------------------------------------------------------------------------------------------------------------- //
