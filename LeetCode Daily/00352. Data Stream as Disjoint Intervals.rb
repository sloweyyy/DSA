class SummaryRanges
    def initialize()
        @seen = {}
        @ranges = {}
        @ends = {}
    end
    def add_num(value)
        return if @seen[value]
        @seen[value] = true
        first = @ends.delete(value - 1) || value
        last = @ranges.delete(value + 1) || value
        @ranges[first] = last
        @ends[last] = first
    end
    def get_intervals()
        @ranges.keys.sort.map { |first| [first, @ranges[first]] }
    end
end
