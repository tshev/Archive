require 'test_helper'

class IndicatorValuesControllerTest < ActionController::TestCase
  setup do
    @indicator_value = indicator_values(:one)
  end

  test "should get index" do
    get :index
    assert_response :success
    assert_not_nil assigns(:indicator_values)
  end

  test "should get new" do
    get :new
    assert_response :success
  end

  test "should create indicator_value" do
    assert_difference('IndicatorValue.count') do
      post :create, indicator_value: { country_id: @indicator_value.country_id, indicator_id: @indicator_value.indicator_id, measure_datetime: @indicator_value.measure_datetime, value: @indicator_value.value }
    end

    assert_redirected_to indicator_value_path(assigns(:indicator_value))
  end

  test "should show indicator_value" do
    get :show, id: @indicator_value
    assert_response :success
  end

  test "should get edit" do
    get :edit, id: @indicator_value
    assert_response :success
  end

  test "should update indicator_value" do
    patch :update, id: @indicator_value, indicator_value: { country_id: @indicator_value.country_id, indicator_id: @indicator_value.indicator_id, measure_datetime: @indicator_value.measure_datetime, value: @indicator_value.value }
    assert_redirected_to indicator_value_path(assigns(:indicator_value))
  end

  test "should destroy indicator_value" do
    assert_difference('IndicatorValue.count', -1) do
      delete :destroy, id: @indicator_value
    end

    assert_redirected_to indicator_values_path
  end
end
