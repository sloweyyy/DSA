class PeekingIterator
    def initialize(iter)
        @iterator = iter
        @cached = false
    end
    def hasNext()
        @cached || @iterator.hasNext()
    end
    def peek()
        unless @cached
            @value = @iterator.next()
            @cached = true
        end
        @value
    end
    def next()
        if @cached
            @cached = false
            @value
        else
            @iterator.next()
        end
    end
end
