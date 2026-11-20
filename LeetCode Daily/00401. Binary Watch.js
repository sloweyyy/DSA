var readBinaryWatch = function(turnedOn) {
    const bits = Array(64).fill(0);
    for (let value = 1; value < 64; value++) bits[value] = bits[value >> 1] + (value & 1);
    const result = [];
    for (let hour = 0; hour < 12; hour++) {
        for (let minute = 0; minute < 60; minute++) {
            if (bits[hour] + bits[minute] === turnedOn) result.push(hour + ":" + String(minute).padStart(2, "0"));
        }
    }
    return result;
};
