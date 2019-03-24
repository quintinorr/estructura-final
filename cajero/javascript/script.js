// Grupo 5 Estructura de datos.
// Encontrar el mínimo número de Billetes y/o monedas para representar una cantidad de dinero dada.
// Creado por Michael Vallejo.

// Listado de monedas soportadas por el sistema.
MONEDAS = [1000, 2000, 200, 100, 50, 25, 20, 10, 5, 1, (25/100), (10/100), (5/100), (1/100)];

// ************************* LISTADO DE FUNCIONES AUXILIARES PARA COMPATIBILIDAD CON C *************************

// Función que ordena los datos del arreglo en forma ascendente.
function Sort(data) {
    return data.sort(function(a, b){ return a-b });
}

// Función que ordena los datos del arreglo en forma descendente.
function SortDescending(data) {
    return data.sort(function(a, b){ return b-a });
}

// Toma el número entero de una cantidad decimal. (Ej.: 2.96 = 2).
function Floor(floatingNumber){
    return Math.floor(floatingNumber);
}

// Función auxiliar que imprime por pantalla un texto.
function PrintLine(text) {
    console.log(text);
}

// Función que devuelve la cantidad de veces que se puede encontrar una moneda en un monto.
function GetCurrencyCount(amount, currency) {
    let quantity = Floor(amount / currency);
    return quantity;
}

// ***************************************** FIN FUNCIONES AUXILIARES ******************************************

// Obtiene el cambio para un monto dado con la menor cantidad de monedas/ billetes posibles.
function GetCash(amount, MONEDAS) {
    if (amount == 0 || MONEDAS.length == 0) { return []; }

    // Arreglo que almacenará la denominación de la moneda y la cantidad de apariciones.
    let Result = [];

    // Variable que almacena temporalmente el monto con el que se está trbajando.
    let tmpAmount = amount;

    // Recorremos el listado de monedas soportadas por el sistema.
    for(let i = 0; i < MONEDAS.length; i++) {
        let currency = MONEDAS[i];
        
        // Dividimos el monto actual entre la denominación de la moneda, para así obtener la cantidad de veces que aparece
        // una denominación en el monto.
        // Ejemplo: 2150 / 2000 = 1.075, esto significa que en ese monto existe una moneda de 2000.
        // Ejemplo: 1925 / 2000 = 0.9625, esto significa que en ese monto no existe una moneda de 2000.
        let quantity = GetCurrencyCount(tmpAmount, currency);

        // Si la denominación de la moneda existe por lo menos una vez en el monto.
        if(quantity > 0) {
            // Al monto actual le restamos la cantidad de veces que aparece la moneda multiplicada por su denominación
            tmpAmount = (tmpAmount - (quantity * currency)).toFixed(5);

            // Agregamos la denominación y su cantidad al resultado.
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
        PrintLine("El sistema no puede realizar el cambio total debido que no no soporta una denominación tan pequeña. Sobran: " + tmpAmount);
    }
    
    return Result;
}

function main() {
    // Monto con el que se desea trabajar. El monto debe ser introducido por el teclado.
    let cash = 1548.43;
    // Arreglo que almacena el resultado del cálculo.
    let arrResult = GetCash(cash, SortDescending(MONEDAS));

    // Imprimimos por por pantalla el resultado del cálculo.
    PrintLine("El monto " + cash + " se divide en: ");
    for(let i = 0; i < arrResult.length; i++) {
        let amount = arrResult[i];

        let text = "- " + amount[1] + " billete de " + amount[0];
        PrintLine(text);
    }

    return 0;
}

main();