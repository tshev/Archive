class ProductController < ApplicationController
    def view
        products = [
            "hello",
            "other"
        ]
        product = products[params[:id].to_i]
        if product != nil
            render :text => "products #{product}"
        else
            raise ActionController::RoutingError.new('Not Found')
        end
    end
end
