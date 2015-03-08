<?hh // strict

interface HttpApi implements Api<HttpParams> {

  public function process(HttpParams $params): string;
}
