<?hh // strict

type ImmParamMap = ImmMap<string, mixed>;
type ParamMap = Map<string, mixed>;

/**
 * HttpParams
 * - Immutable collection of HTTP params.
 * - Supported params: POST, GET.
 */
final class HttpParams {

  public function __construct(
      private ImmParamMap $postMap,
      private ImmParamMap $getMap
  ) {}

  public function getPostParams(): ImmParamMap {
    return $this->postMap;
  }
  
  public function getGetParams(): ImmParamMap {
    return $this->getMap;
  }
}
