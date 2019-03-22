// Grupo 6 Estructura de datos. Projgrama que simla un cajero automático en JavaScript.
// Creado por Michael Vallejo.

// Los centavos se representan en base a 100.
// MONEDAS = [1000, 2000, 500, 200, 100, 50, 20, 10, 5, 1, (25/100), (10/100), (5/100), (1/100)];
MONEDAS = [1000,  500, 100, 50, 20, 10, 5, 1, (25/100), (10/100), (5/100), (1/100)];

// Ordena los datos del arreglo en forma descendente.
function Sort(data) {
    return data.sort(function(a, b){return b-a});
}

// Obtiene la cantidad mínima de billetes posibles para un monto dado.
function GetCash(amount) {
    MONEDAS = Sort(MONEDAS);

    let Result = [];
    let tmpAmount = amount;

    for(let i = 0; i < MONEDAS.length; i++) {
        let currency = MONEDAS[i];
        
        // Si dividimos el monto restante entre la moneda actual y nos da como resultado un valor mayor a 1,
        // significa que el monto contiene almenos una de esas monedas.
        // Ejemplo: 2150 / 2000 = 1.075, esto significa que en ese monto existe una moneda de 2000.
        // Ejemplo: 1925 / 2000 = 0.9625, esto significa que en ese monto no existe una moneda de 200.

        let div = (tmpAmount / currency);
        // Redondeamos la división para obtener la cantidad entera de monedas.
        let quantity = Math.floor(div);

        if(quantity > 0) {
            tmpAmount = (tmpAmount - (quantity * currency)).toFixed(5);
            Result.push([currency, quantity]);
        }
        // Si ya se han obtenido todas las monedas, ya no tenemos por qué seguir ejecutando el bucle, así que salimos de él.
        if(tmpAmount <= 0) {
            tmpAmount = 0;
            break;
        }
    }

    // Entra en esta condición si no hay una denominación que supla el cambio solicitado. (si el cliente solicita centavo, pero centavo no es una moneda agregada al sistema).
    if( tmpAmount > 0) {
        // Si las denominaciones que soporta el sistema son 1000, 500 y 200 y el monto solicitado es 1300; según el cálculo anterior, sobraran 100 pesos, 
        // por lo que se debe recalcular para que el sistema devuelva 4 monedas de 200 y una de 500, en vez de una de 1000 y una de 200 (y sobren 100).
        //
        // TODO
        //
        console.log("Sobra dinero:" + tmpAmount);
    }
    
    return Result;
}

function main() {
    let cash = 1548.43;
    var arrResult = GetCash(cash);
    console.log("El monto " + cash + " se divide en: ");
    for(let i = 0; i < arrResult.length; i++) {
        let res = arrResult[i];
        Print(res);
    }
}

function Print(amount, quantity) {
    let text = "- " + amount[1] + " billete de " + amount[0];
    console.log(text);
}

main();