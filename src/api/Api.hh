<?hh // strict

interface Api<TParams> {

  public function process(TParams $params): string;
}
