let queenRow = 1;
let queenCol = 6;
let moveX, moveY;

moveX = queenRow;
moveY = queenCol;

let diagonalLeftRow =  0;
let diagonalLeftCol=   moveY - (moveX);

let diagonalRightCol = (moveX) + moveY;
let diagonalRightRow = 0;

for(let row = 0; row < 9 ;row++)
{
    let text='';

    for(let col  = 0; col <  9; col++ ){
        if(col == 0 && row != 0){
            text += row.toString() + ' ';
        }
        else if(row == 0 && col != 0){
            text += col.toString() + ' ';
        }
        else if (col == moveY && row == moveX){
            text +='R ';
        }
        else if(moveY == col){
            text +='* ';
        }
        else if(row == moveX){
            text +='* ';
        }
        else if(diagonalLeftRow == row && col == diagonalLeftCol){
            text +='* ';


        }
        else if(diagonalRightRow == row && col == diagonalRightCol){
            text +='* ';
        }
        else{
            text +='+ ';
        }
    }

    diagonalLeftRow++;
    diagonalLeftCol++;

    diagonalRightCol--;
    diagonalRightRow++;

    console.log(text);
}
