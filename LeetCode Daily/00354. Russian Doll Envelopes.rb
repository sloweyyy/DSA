def max_envelopes(envelopes)
    envelopes.sort_by! { |width, height| [width, -height] }
    tails = []
    envelopes.each do |_, height|
        left = 0
        right = tails.length
        while left < right
            middle = left + (right - left) / 2
            if tails[middle] < height
                left = middle + 1
            else
                right = middle
            end
        end
        tails[left] = height
    end
    tails.length
end
