const readline = require('readline');
const crypto = require('crypto');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
const ask = prompt => new Promise(res => rl.question(prompt, res));

function secretsChoice(arr) {
    return arr[crypto.randomInt(arr.length)];
}

function gamblingSort(arr) {
    const n = arr.length;
    function sortCheck(arr) {
        if (n < 2) return true;
        for (let i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        console.log(arr);
        return true;
    }

    while (!sortCheck(arr)) {
        for (let j = 0; j < n; j++) {
            const firstNum = secretsChoice(arr);
            const secondNum = secretsChoice(arr);
            if (arr.indexOf(firstNum) === arr.indexOf(secondNum)) continue;
            const i = arr.indexOf(firstNum);
            const k = arr.indexOf(secondNum);
            [arr[i], arr[k]] = [arr[k], arr[i]];
            console.log(arr);
        }
    }
    return arr;
}

async function main() {
    const size = parseInt(await ask("Size of the array: "));
    const minValue = parseInt(await ask("Minimum value of the array: "));
    const maxValue = parseInt(await ask("Maximum value of the array: "));
    rl.close();
    const arr = Array.from({ length: size }, () => crypto.randomInt(minValue, maxValue + 1));
    console.log(arr);
    gamblingSort(arr);
}

main();