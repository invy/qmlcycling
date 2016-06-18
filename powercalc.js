
var estimateGravPower = function(deltaT, deltaS, slope, overallWeight) {
    var g = 9.81;
    var power = ((deltaS *
                  slope *
                  g * (overallWeight)) /
                  (100 * deltaT));
    return power;
}

var estimateAerodynamicPower = function(speedMS, rho, cyclistArea, dragCoefficient) {
//    var density = (1.293 - 0.00426 * temperaturev) * Math.exp(-elevationv / 7000.0);
    var aeroValues = [0.388, 0.445, 0.420, 0.300, 0.233, 0.200];
    var power = (0.5 * rho * Math.pow((speedMS), 3) * cyclistArea * dragCoefficient);
    return power;
}

var estimateRollResistPower = function(overallWeight) {
    var g = 9.81;
    var tireValues = [0.005, 0.004, 0.012];
    var C = tireValues[0];
    var F = C * g*overallWeight;
    return 0;
}

var estimatePower = function(deltaT, deltaS, speedMS, slope, overallWeight, rho, cyclistArea, dragCoefficient)
{
    var power = 0;
    // power to counteract gravity
    power = estimateAerodynamicPower(speedMS, rho, cyclistArea, dragCoefficient)
          + estimateGravPower(deltaT, deltaS, slope, overallWeight)
          + estimateRollResistPower(overallWeight);
    return power > 0 ? power : 0;
}
