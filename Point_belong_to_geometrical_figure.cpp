/* Point belong to geometrical figure - application check if the point belong to geometrical figure. */

#include <iostream>
#define USE_MATH_DEFINES
#include <math.h>
#include <conio.h>              //Library for responsive control.

using namespace std;

double Ax = 0, Ay = 0, Bx = 4, By = 0, Cx = 2, Cy = 4, Mx = 2, My = 2;

int main()
{
    
    auto Pythagoras = [](auto x1, auto y1, auto x2, auto y2) {return hypot(x1 - x2, y1 - y2); };

    auto Field = [](auto x1, auto y1, auto x2, auto y2, auto x3, auto y3) {return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)); };
    
    cout << "##### Point belong to figure #####\n##### Main Menu #####" << endl;

    cout << "Which geometrical figure you want to check the belonging of the point M ?" << endl;

    cout << "1 - Triangle.\n";

    cout << "Enter correctly figure number from 1 to 1: ";

    char switch_on = _getch();

    switch (switch_on)
    {

    case '1':

        auto AB_Length = Pythagoras(Ax, Ay, Bx, By);

        auto BC_Length = Pythagoras(Bx, By, Cx, Cy);

        auto AC_Length = Pythagoras(Ax, Ay, Cx, Cy);

        auto Field_ABC = Field(Ax, Ay, Bx, By, Cx, Cy);

        auto FieldSumary = Field(Ax, Ay, Bx, By, Mx, My) + Field(Bx, By, Cx, Cy, Mx, My) + Field(Ax, Ay, Cx, Cy, Mx, My);

        cout << "AB side length = " << AB_Length << "\nBC side length = " << BC_Length << "\nAC side length = " << AC_Length << "\nABC Triangle area = " << Field_ABC << endl;

        (Field_ABC == FieldSumary) ? cout << "The point belong to triangle ABC." << endl : cout << "The point don't belong to triangle ABC." << endl;
        
        break;

    default:

        break;
    }

    //system("cls");

    return 0;
}