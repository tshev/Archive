package controllers

import anorm._
import play.api._
import play.api.db.DB
import play.api.mvc._
import play.api.Play.current
import play.libs.F.Tuple

import scala.collection.JavaConverters._

/**
 * Created by taras on 7/20/15.
 */
case class Item(name:String, body:String)

object Blog extends Controller {
  def index = Action {
    DB.withConnection { implicit c =>
      val a = SQL("SELECT * from posts;")().map(row =>
                                                Item(row[String]("name"), row[String]("body")))
      Ok(views.html.blog(a))
    }
  }
}
