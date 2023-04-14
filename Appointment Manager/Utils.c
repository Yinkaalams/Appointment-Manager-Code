//prog71985 - winter23 - Group Project ON Appointment Manager - Group 18 - Ehinomhen Osezuah and Yinus Alamutu
//Utility Implementation
void removeTrailingNewline(char* str)
{
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}