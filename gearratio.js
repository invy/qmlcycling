
var gerRatios = function(speed, wheelRadius, smallChainRing, largeChainRing, minSprocket, maxSprocket) {
    var wheelRpm = speed/wheelRadius;
    var transmission = wheelRpm/90.0;

    var minLarge = largeChainRing/minSprocket;
    var maxLarge = largeChainRing/maxSprocket;
    var minSmall = smallChainRing/minSprocket;
    var maxSmall = smallChainRing/maxSprocket;
}
