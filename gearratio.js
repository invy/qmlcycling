
/*
 * @speed in m/s
 * @wheelRadius in meters
 * @smallChainRing
 * @largeChainRing
 * @minSprocket
 * @maxSprocket
 */


var getCogForRpm = function(cranksRpm, wheelRpm, chainRing, minSprocket, maxSprocket) {
    var transmission = wheelRpm / cranksRpm;
    var cog = Math.round(chainRing / transmission);
    if(cog < maxSprocket && cog > minSprocket)
        return cog;
    return 0;
}

var propritize = function(gearing) {

}

var getRatiosForCR = function(speed, wheelRadius, chainRing, minSprocket, maxSprocket) {

    var GearsInfo = function(rpm, chainRing, cog) {
        this.rpm = rpm;
        this.chainRing = chainRing;
        this.cog = cog;
    }

    var pedalRpm = [90, 80, 70, 60];

    if(wheelRadius === 0)
        return [];
    var wheelRpm = (speed/2*Math.PI*wheelRadius)*60;
    if(wheelRpm === 0)
        return [];

    var gearing = [];
    var i = 0;

    for(var r in pedalRpm) {
        var rpm = pedalRpm[r];
        var cog = getCogForRpm(rpm, wheelRpm, chainRing, minSprocket, maxSprocket);
        if(cog !== 0) {
            gearing[i] = new GearsInfo(rpm, chainRing, cog);
            ++i;
        }
    }

    return gearing;
}
