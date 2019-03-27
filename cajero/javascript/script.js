// Grupo 5 Estructura de datos.
// Encontrar el mínimo número de Billetes y/o monedas para representar una cantidad de dinero dada.
// Creado por Michael Vallejo.

// Listado de monedas soportadas por el sistema.
// CURRENCIES = [1000, 2000, 200, 100, 50, 25, 20, 10, 5, 1, (25/100), (10/100), (5/100), (1/100)];
var CURRENCIES = [1000, 500, 200];
var RESULT = [];

// ************************* LISTADO DE FUNCIONES AUXILIARES PARA COMPATIBILIDAD CON C *************************

// Función auxiliar que imprime por pantalla un texto.
function PrintLine(text) {
    console.log(text);
}

// Toma el número entero de una cantidad decimal. (Ej.: 2.96 = 2).
function Floor(floatingNumber){
    return Math.floor(floatingNumber);
}

// Función que devuelve la cantidad de veces que se puede encontrar una moneda en un monto.
function GetCurrencyCount(amount, currency) {
    let quantity = Floor(amount / currency);
    return quantity;
}

function AddToArray(arr, data){
    arr.push(data);
    return arr;
}

function AddToResult(data) {
    RESULT = AddToArray(RESULT, data);
}

// ***************************************** FIN FUNCIONES AUXILIARES ******************************************

function Recursion(amount, MONEDAS, currency) {

    let count = GetCurrencyCount(amount, currency);
    let originalAmount = amount;
    amount = amount - (count * currency);
    
    if (amount == 0) {
        AddToResult([currency, count]);
        return 0; 
    }
    
    if(MONEDAS.length == 0)
    {
            return amount; 
    }

    let newCurrency = MONEDAS[0];
    let MO = MONEDAS.slice(1, MONEDAS.length);

    for(let i = count; i + 1 > 0; i--) {

        let tmp = originalAmount - (currency * i);
        amount =  Recursion(tmp, MO, newCurrency);
        
        if(amount == 0 && i > 0) {
            AddToResult([currency, i]);
            return 0;
        }

    }
    return amount;
}

function GetCash(amount){
    let MONEDAS = CURRENCIES;

    for (let i = 0; i < MONEDAS.length; i++){
        RESULT = [];
        
        let currency = MONEDAS[i];
        let SUBCURRENCIES = MONEDAS.slice(i + 1, MONEDAS.length);
        let res = Recursion(amount, SUBCURRENCIES, currency);
        
        if(res == 0) { break; }
    }

    return RESULT;
}

function main() {
    // Monto con el que se desea trabajar. El monto debe ser introducido por el teclado.
    let cash = 1350;
    let arrResult = GetCash(cash);

    if(arrResult.length > 0) {
        // Imprimimos por por pantalla el resultado del cálculo.
        PrintLine("El monto " + cash + " se divide en: ");
        for(let i = 0; i < arrResult.length; i++) {
            let amount = arrResult[i];

            let text = "- " + amount[1] + " billete de " + amount[0];
            PrintLine(text);
        }
    } else {
        PrintLine("No se ha podido realizar el cambio del monto solicitado. El sistema no posee ese tipo de cambio. Digite un monto válido.");
    }

    return 0;
}

main();