class VmstatController < ApplicationController
  def index
  end
	def show
	end
  def turner
		
#		%x(echo "ds" > /home/tshev/dds)
		respond_to do |f|
			f.html
			f.json { render json: solve_to_json }
		end
  end
private
	def solve_to_json
		prm = params[:vmstat][:command]
		{ :out => %x(com2 #{prm}).to_s}
	end
end
