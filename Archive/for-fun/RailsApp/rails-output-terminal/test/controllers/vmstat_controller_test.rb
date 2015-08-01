require 'test_helper'

class VmstatControllerTest < ActionController::TestCase
  test "should get index" do
    get :index
    assert_response :success
  end

  test "should get turner" do
    get :turner
    assert_response :success
  end

end
