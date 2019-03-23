
public abstract class ArticleNames{
  String ArticleName;
  String ArticleType;
  String QuantityName;
  double Price1;
  double Quantity;
  public ArticleNames() {
	  ArticleName = ArticleType = QuantityName = " ";
 	  Price1 = Quantity = 0.0;
  }
  String getArticle( ) {
	  return ArticleName;
  }
  void setArticle ( String article ) {
	  ArticleName = article;
  }
  String getType( ) {
	  return ArticleType;
  }
  void setType ( String type ) {
	  ArticleName = type;
  }
  String getQuantityName( ) {
	  return QuantityName;
  }
  void setQuanName( String quanname ) {
	  QuantityName = quanname;
  }
  double getQuantity( ) {
	  return Quantity;
  }
  void setQuantity ( double quan ) {
	  Quantity = quan;
  }
  double getPrice( ) {
	  return Price1;
  }
  void setPrice ( double pr ) {
	  Price1 = pr;
  }
}
