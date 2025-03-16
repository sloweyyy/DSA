function repairCars(ranks: number[], cars: number): number {
    // Function to check if all cars can be repaired within time t
    const canRepairAllCars = (t: number): boolean => {
        let totalCarsRepairable = 0;

        for (let i = 0; i < ranks.length; i++) {
            // For each mechanic, calculate how many cars they can repair in time t
            // If a mechanic with rank r can repair n cars in r*n² time,
            // then in time t, they can repair sqrt(t/r) cars
            const carsRepairable = Math.floor(Math.sqrt(t / ranks[i]));
            totalCarsRepairable += carsRepairable;

            // Early return if we already have enough capacity
            if (totalCarsRepairable >= cars) {
                return true;
            }
        }

        return totalCarsRepairable >= cars;
    };

    // Binary search for the minimum time
    let left = 0;
    let right = 1e14; // Increased upper bound to handle larger inputs

    while (left < right) {
        const mid = Math.floor((left + right) / 2);

        if (canRepairAllCars(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
