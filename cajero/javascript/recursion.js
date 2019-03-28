// Grupo 5 Estructura de datos.
// Encontrar el mínimo número de Billetes y/o monedas para representar una cantidad de dinero dada.
// Creado por Michael Vallejo.

// Listado de monedas soportadas por el sistema.
// var CURRENCIES = [1000, 2000, 200, 100, 50, 25, 20, 10, 5, 1, (25/100), (10/100), (5/100), (1/100)];
var CURRENCIES = [1000, 500, 200, 50, 25, 10, 5, 3, 1];
var RESULT = [];

// ************************* LISTADO DE FUNCIONES AUXILIARES PARA COMPATIBILIDAD CON C *************************

// Función que ordena los datos del arreglo en forma descendente.
function SortDescending(data) {
    return data.sort(function(a, b){ return b-a });
}

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

//Agrega un elemento a un arreglo.
function AddToArray(arr, data){
    arr.push(data);
    return arr;
}

//Agrega el valor de la moneda al arreglo de resultado.
function AddToResult(data) {
    RESULT = AddToArray(RESULT, data);
}

function GetResAmount(amount, currency, count) {
    let result = amount - (count * currency);
    return result;
}

// ***************************************** FIN FUNCIONES AUXILIARES ******************************************

function Recursion(amount, MONEDAS, currency) {
    // Almacenamos el monto original en otra variable.
    let originalAmount = amount;
    //Obtenemos la cantidad máxima de apariciones que puede tener una denomicación en un monto dado.
    let count = GetCurrencyCount(amount, currency);
    // Le restamos la cantidad máxima de apariciones de una denominación al monto total.
    // Ej: 1300: 1000 * 1 = 1000 -> 1300 - 1000 = 300.
    amount = GetResAmount(amount, currency, count);
    // Si el resultado de la resta es cero, significa que el monto es múltiplo de la denominación con la que estamos trabajando por lo
    // que agregamos el la moneda y la cantidad de apariciones en el arreglo de resultado y el calculo termina.
    if (amount == 0) {
        AddToResult([currency, count]);
        return 0; 
    }
    // Si el arreglo de monedas suplido ya no contiene elemento, se retorna el monto restante del cálculo.
    if(MONEDAS.length == 0)
    {
        return amount; 
    }
    // Almacena la primera moneda que contiene el arreglo en ese momento. (osea, la moneda que en la lista original va despues de la moneda almacenada en currency).
    let newCurrency = MONEDAS[0];
    // Elimina del arreglo la moneda que almacenamos arriba.
    let MO = MONEDAS.slice(1, MONEDAS.length);

    // Este ciclo realiza diferentes combinaciones dependiendo de la cantidad de veces que aparezca una monedas en el monto.
    // Ejemplo: en el monto 1300, la moneda 500 aparece 2 veces por lo que las combinaciones que se pueden hacer con 500 son 2, 1 de 500 y 4 de 200
    // o 2 de 500 y 1 de 300 en caso de existan esas denominaciones.
    for(let i = count; i + 1 > 0; i--) {
        // Le restamos la cantidad máxima de apariciones de una denominación al monto total.
        let tmp = GetResAmount(originalAmount, currency, i);
        // Llamamos al mismo método de forma recursiva, pero esta vez le pasamos un nuevo arreglo y le decimos que va a trabajar con otra meneda.
        amount =  Recursion(tmp, MO, newCurrency);
        
        // Si el monto devuelto por la recursión es igual a cero significa que se ha encontrado el el cambio total, por lo que vamos a gregando al
        // arreglo de resultado cada una de las monedas/denomiaciones utilizadas para encontrar esta recursión. Tambien terminamos el ciclo porque
        // ya no es necesario seguir recorriendolo.
        if(amount == 0 && i > 0) {
            AddToResult([currency, i]);
            break;
        }

    }
    // Retornamos el monto calculado.
    return amount;
}

function GetCash(amount){
    // Almacenamos las monedas que soporta el sistema en un arreglo local y la ordenamos de forma descendente para trabajar primero desde la mayor denominación.
    let MONEDAS = SortDescending(CURRENCIES);

    // Recorremos cada una de las monedas soportadas por el sistema.
    for (let i = 0; i < MONEDAS.length; i++){
        // Limpiamos la variable resultado por cada una de las iteraciones que realizamos.
        RESULT = [];
        // Obtenemos la variable actual.
        let currency = MONEDAS[i];
        // Eliminamos la moneda actual el arreglo de moneda.
        let SUBCURRENCIES = MONEDAS.slice(i + 1, MONEDAS.length);
        // Llamamos a la funsión que realiza el cálculo de efectivo. Le enviamos como parámetro el monto con el que se desea trabajr, el listado de monedas
        // soportadas por el sistema y que se encuentren despues de la moneda actual.
        let res = Recursion(amount, SUBCURRENCIES, currency);
        // Si el resultado devuelto por la recursion es cero, significa que el sistema encontró la combinación correcte por lo que terminamos el bucle.
        if(res == 0) { break; }
    }
    // Devolvemos el arreglo que contiene el resultado del cálculo.
    return RESULT;
}

function main() {
    // Monto con el que se desea trabajar. El monto debe ser introducido por el teclado.
    let cash = 1300;
    // Almacenamos el arreglo con el resultado del cálculo.
    let arrResult = GetCash(cash);

    // Si el arreglo no contiene ningún elemento significa que no se pudo encontrar el cambio exacto al monto suplido.
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