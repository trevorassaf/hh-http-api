<?hh // strict

/**
 * HttpParamsBuilder
 * - Assembles HttpParams instance with client-defined params.
 */
final class HttpParamsBuilder implements Builder<HttpParams> {

  private ParamMap $postMap;
  private ParamMap $getMap;

  public function __construct() {
    $this->postMap = Map{};
    $this->getMap = Map{};
  }

  public function bindPostParam(string $key, mixed $value): this {
    $this->postMap[$key] = $value;
    return $this;
  }

  public function unsetPostParam(string $key): this {
    if ($this->postMap->contains($key)) {
      $this->postMap->remove($key);
    }

    return $this;
  }
  
  public function bindGetParam(string $key, mixed $value): this {
    $this->getMap[$key] = $value;
    return $this;
  }

  public function unsetGetParam(string $key): this {
    if ($this->getMap->contains($key)) {
      $this->getMap->remove($key);
    }

    return $this;
  }
  
  public function build(): HttpParams {
    return new HttpParams(
        new ImmMap($this->postMap),
        new ImmMap($this->getMap)
    ); 
  }  
}

