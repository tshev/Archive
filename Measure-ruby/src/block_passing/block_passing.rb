require "benchmark"

def explicit_block_passing(x, y, operation)
	operation.call(x, y)
end

def implicit_block_passing(x, y)
	yield(x, y)
end
N = 100000
Benchmark.bmbm(15) do |report|
  power = lambda { |x, y| x**y }
	report.report("explicit_block_passing with random") do
		N.times { |i| explicit_block_passing(5, (N-i)/(i+1)+rand*10, power) }
	end

	report.report("implicit_block_passing with random") do
	  N.times { |i| implicit_block_passing(5, (N-i)/(i+1)+rand*10) { |x, y| x**y } }
	end
	report.report("explicit_block_passing without random") do
		N.times { |i| explicit_block_passing(5, (N-i)/(i+1)+10, power) }
	end
	report.report("implicit_block_passing without random") do
		N.times { |i| implicit_block_passing(5, (N-i)/(i+1)+10) { |x, y| x**y } }
	end
end
