#include <iostream>
using namespace std;
 
void printMazePath(int endrow, int endcol, int curr_row, int curr_col, string osf = "")
{
	if(curr_row == endrow && curr_col == endcol)
    {
		cout<<osf<<"\n";
		return;
	}
	if(curr_row > endrow || curr_col > endcol)
		return;

	printMazePath(endrow, endcol, curr_row, curr_col+1, osf+"H");
	printMazePath(endrow, endcol, curr_row+1, curr_col, osf+"V");
 
}

void printDiagonalMazePath(int endrow, int endcol, int curr_row, int curr_col, string osf = "")
{
	if(curr_row == endrow && curr_col == endcol)
    {
		cout<<osf<<"\n";
		return;
	}
	if(curr_row > endrow || curr_col > endcol)
		return;

	printDiagonalMazePath(endrow, endcol, curr_row, curr_col + 1, osf+"H");
	printDiagonalMazePath(endrow, endcol, curr_row + 1, curr_col, osf+"V");
    printDiagonalMazePath(endrow, endcol, curr_row + 1, curr_col + 1, osf + "D");
}
 
int main()
{
    cout << "Straight Paths\n";
	printMazePath(2,2,0,0);
    cout << "\nDiagonal Paths\n";
    printDiagonalMazePath(2, 2, 0, 0);
	return 0;
}