/* Point belong to geometrical figure - application check if the point belong to geometrical figure. */

#include <iostream>
#define USE_MATH_DEFINES
#include <math.h>
#include <conio.h>              //Library for responsive control.
#include <iomanip>

using namespace std;

double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, Mx, My;

int main()
{

    auto Pythagoras = [&](auto x1, auto y1, auto x2, auto y2) {return hypot(x1 - x2, y1 - y2); };

    auto Field = [&](auto x1, auto y1, auto x2, auto y2, auto x3, auto y3) {return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)); };

    cout << "##### Point belong to figure #####\n########## Main Menu ##########" << endl;

    cout << "Which geometrical figure you want to check the belonging of the point M ?" << endl;

    cout << "1 - Rectangle.\n2 - Triangle.\n";

    cout << "Enter correctly figure number from 1 to 2: ";

    char switch_on = _getch();

    switch (switch_on)
    {

    case '1':
    {
        cout << "Please enter vertices coordinates of the rectangle and M point coordinates\nin order: Ax Ay Bx By Cx Cy Dx Dy Mx My: ";

        cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy >> Mx >> My;

        auto AB_SideLength = Pythagoras(Ax, Ay, Bx, By);

        auto BC_SideLength = Pythagoras(Bx, By, Cx, Cy);

        auto CD_SideLength = Pythagoras(Cx, Cy, Dx, Dy);

        auto DA_SideLength = Pythagoras(Dx, Dy, Ax, Ay);

        auto ABCD_Field = Field(Ax, Ay, Bx, By, Cx, Cy) + Field(Ax, Ay, Cx, Cy, Dx, Dy);

        auto FieldSum = Field(Ax, Ay, Bx, By, Mx, My) + Field(Bx, By, Cx, Cy, Mx, My) + Field(Cx, Cy, Dx, Dy, Mx, My) + Field(Dx, Dy, Ax, Ay, Mx, My);

        cout << setprecision(4) << "\n##### Rectangle ABCD #####\nAB side length = " << AB_SideLength << "\nBC side length = " << BC_SideLength << "\nCD side length = " << CD_SideLength << "\nDA side length = " << DA_SideLength << "\nABCD Rectangle area = " << ABCD_Field << endl;

        (ABCD_Field == FieldSum) ? cout << "Point M(" << Mx << ", " << My << ") belong to rectangle ABCD." << endl : cout << "Point M(" << Mx << ", " << My << ") don't belong to rectangle ABCD." << endl;
    }
    break;

    case '2':
    {
        cout << "Please enter vertices coordinates of the triangle and M point coordinates\nin order: Ax Ay Bx By Cx Cy Mx My: ";

        cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Mx >> My;

        auto AB_SideLength = Pythagoras(Ax, Ay, Bx, By);

        auto BC_SideLength = Pythagoras(Bx, By, Cx, Cy);

        auto CA_SideLength = Pythagoras(Cx, Cy, Ax, Ay);

        auto ABC_Field = Field(Ax, Ay, Bx, By, Cx, Cy);

        auto FieldSum = Field(Ax, Ay, Bx, By, Mx, My) + Field(Bx, By, Cx, Cy, Mx, My) + Field(Ax, Ay, Cx, Cy, Mx, My);

        cout << setprecision(4) << "\n##### Triangle ABC #####\nAB side length = " << AB_SideLength << "\nBC side length = " << BC_SideLength << "\nCA side length = " << CA_SideLength << "\nABC Triangle area = " << ABC_Field << endl;

        (ABC_Field == FieldSum) ? cout << "Point M(" << Mx << ", " << My << ") belong to triangle ABC." << endl : cout << "Point M(" << Mx << ", " << My << ") don't belong to triangle ABC." << endl;
    }
    break;

    default:
    {
        cout << "The function number is false!\nPlease enter the correctly function number." << endl;
    }
    break;

    }

    return 0;
}