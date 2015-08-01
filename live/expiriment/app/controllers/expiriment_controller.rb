class ExpirimentController < ApplicationController
    def welcome
        name = params[:name] || "Taras"
        render :text => "Hello, #{name}"
    end
end
