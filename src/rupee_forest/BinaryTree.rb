module BinaryTree
  class Node
    # our three features:
    attr_reader :value
    attr_accessor :left, :right

    def initialize(v)
      @value = v
      @left = Node.new
      @right = Node.new
    end

    def insert(v)
      case value <=> v
      when 1 then insert_left(v)
      when -1 then insert_right(v)
      when 0 then false # the value is already present
      end
    end

    def inspect
      "{#{value}::#{left.inspect}|#{right.inspect}}"
    end

    private

      def insert_left(v)
        if left
          left.insert(v)
        else
          self.left = Node.new(v)
        end
      end

      def insert_right(v)
        if right
          right.insert(v)
        else
          self.right = Node.new(v)
        end
      end
  end
end