function spline(x,points){
    for(let i = 0; i < points.length - 1; i++){
        if(x >= points[i].x && x <= points[i+1].x){
            let x0 = points[i].x;
            let y0 = points[i].y;
            let x1 = points[i+1].x;
            let y1 = points[i+1].y;
            
            let slope = (y1 - y0) / (x1 - x0);
            return y0 + slope * (x-x0);
        }
    }
}
let points = [
    { x: 2, y: 9.5 },
    { x: 4, y: 8.0 },
    { x: 6, y: 10.5 },
    { x: 8, y: 39.5 },
    { x: 10, y: 72.5 }
];
let x = 4.5;
console.log(spline(x,points));
