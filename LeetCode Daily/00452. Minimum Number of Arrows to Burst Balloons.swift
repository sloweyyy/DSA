class Solution {
    func findMinArrowShots(_ points: [[Int]]) -> Int {
        let sorted = points.sorted {
            $0[1] < $1[1]
        };
        var arrows = 0;
        var position: Int? = nil;
        for balloon in sorted {
            if position == nil || balloon[0] > position! {
                arrows += 1;
                position = balloon[1];
            }
        };
        return arrows;
    }
}
