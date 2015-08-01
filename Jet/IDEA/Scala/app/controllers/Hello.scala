package controllers

import play.api.mvc.{Action, Controller}

/**
 * Created by taras on 7/20/15.
 */
object Hello extends Controller {
  def index = Action {
    Ok("Hello, world")
  }
  def custom_greating(name: String) = Action {
    Ok("Hello, " + name)
  }
}
