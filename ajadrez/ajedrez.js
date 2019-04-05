let queenRow = 1;
function getMovementsAllowedQueen(queenCol, queenRow){
  
  let position = {
    col : null,
    row : null
  };

  let movementsAllowedoQueen = [];
  let moveX, moveY;

  moveX = queenRow;
  moveY = queenCol;

  let diagonalLeftRow =  0;
  let diagonalLeftCol=   moveY - (moveX);

  let diagonalRightCol = (moveX) + moveY;
  let diagonalRightRow = 0;

  for(let row = 0; row < 9 ;row++)
  {
      for(let col  = 0; col <  9; col++ ){

        let isAllowed = false;

          if(moveY == col){
            isAllowed = true;
          }
          else if(row == moveX){
            isAllowed = true;
          }
          else if(diagonalLeftRow == row && col == diagonalLeftCol){
            isAllowed = true;
          }
          else if(diagonalRightRow == row && col == diagonalRightCol){
            isAllowed = true;           
          }

        if (isAllowed){
          position ={
            col : col,
            row : row
          };
          movementsAllowedoQueen.push(position);
        }
      }


      diagonalLeftRow++;
      diagonalLeftCol++;

      diagonalRightCol--;
      diagonalRightRow++;
  }

  return movementsAllowedoQueen;
}



function drawTable(queenPositionCol, queenPositionRow) {

let movementsAllowedQueen = [];

movementsAllowedQueen = getMovementsAllowedQueen(queenPositionCol,queenPositionRow);

  for(let roq = 0; roq < 9; roq++){

    let text = '';

    for(let col = 0; col < 9 ; col++){

      let allow= movementsAllowedQueen.find(x=> x.row == roq && x.col == col);

      if(roq == 0 && col == 0){
        text += 'x ';
      }
      else if(roq == 0 && col != 0){
        text += col.toString() + ' ';
      }
      else if(col == 0 && roq != 0){
        text += roq.toString() + ' ';
      }
      else if (col == queenPositionCol && roq == queenPositionRow){
        text +='R ';
      }
      else if (allow){
        text +='* ';
      }      
      else{
        text +='+ ';
      }

    }

    console.log(text);

  }

};

function readNewPosition ()
{
  let position = {
    col : 7,
    row :5
  };

  return position;  
}

function readOpcion()
{
  let numero = 1;
  return numero;    
}


function play()
{
  let queenInitialposition = {
    col : 4,
    row : 8
  };

  drawTable(queenInitialposition.col, queenInitialposition.row);

  let opcion = 1;
  do {
    console.log('¿Desea mover a la reyna?')
    console.log('1: Si');
    console.log('2: No');

    opcion = readOpcion();

    if(opcion == 1)
    {
      let newPosition = readNewPosition();
      console.clear();
      drawTable(newPosition.col, newPosition.row);
    }

  }
  while (opcion != 2);


}

/*play();*/
