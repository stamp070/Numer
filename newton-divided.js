// linear
// let x = [0,800000];
// let y = [9.81,9.5682];

//quadratic
// let x = [0,40000,80000];
// let y = [9.81,9.6879,9.5682];

//polynomial
let x = [0,20000,40000,60000,80000];
let y = [9.81,9.7487,9.6879,9.6879,9.5682];

function calculate(x,y,left,right,memory={}){
    if(left === right){
        return y[left];
    }
    let key = `${left}:${right}`;
    if(key in memory){
        return memory[key];
    }
    memory[key] = (calculate(x,y,left,right+1)-calculate(x,y,left-1,right))/(x[left]-x[right]);
    return memory[key]; // last one
}
let value = 40498;
let memory = {};

let result = y[0];
for(let i=1;i<x.length;i++){
    let Ci = calculate(x,y,i,0,memory);
    for(let j=0;j<i;j++){
        Ci *= value-x[j];
    }
    result += Ci;
}
console.log(result);
